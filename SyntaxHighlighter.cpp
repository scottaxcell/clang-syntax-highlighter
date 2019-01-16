//
// Created by saxcell on 1/15/19.
//

#include <iostream>
#include "SyntaxHighlighter.h"
#include "clang-c/Index.h"

SyntaxHighlighter::SyntaxHighlighter() {
    m_translationUnit = 0;

    m_highlightMap[CXToken_Punctuation] = "black";
    m_highlightMap[CXToken_Keyword] = "green";
    m_highlightMap[CXToken_Identifier] = "black";
    m_highlightMap[CXToken_Literal] = "red";
    m_highlightMap[CXToken_Comment] = "blue";

    m_index = clang_createIndex(0, 0);
}

SyntaxHighlighter::~SyntaxHighlighter()
{
    clang_disposeTranslationUnit(m_translationUnit);
    clang_disposeIndex(m_index);
}

std::string getClangString(CXString str) {
    const char* tmp = clang_getCString(str);
    if (tmp == NULL) {
        return "";
    }
    else {
        std::string translated = std::string(tmp);
        clang_disposeString(str);
        return translated;
    }
}

CXChildVisitResult visitor(CXCursor cursor, CXCursor parent, CXClientData clientData) {
    SyntaxHighlighter* sh = static_cast<SyntaxHighlighter*>(clientData);

    CXFile file;
    unsigned int line;
    unsigned int column;
    unsigned int offset;

    CXSourceLocation loc = clang_getCursorLocation(cursor);
    clang_getFileLocation(loc, &file, &line, &column, &offset);

    // Only interested in tokens in the current file
    if (getClangString(clang_getFileName(file)) != sh->getCurrentFile()) {
        return CXChildVisit_Continue;
    }

    CXTranslationUnit tu = clang_Cursor_getTranslationUnit(cursor);
    CXSourceRange range = clang_getCursorExtent(cursor);

    CXToken* tokens;
    unsigned int numTokens;
    clang_tokenize(tu, range, &tokens, &numTokens);

    if (numTokens > 0) {
        for (unsigned int i = 0; i < numTokens - 1; i++) {
            std::string token = getClangString(clang_getTokenSpelling(tu, tokens[i]));
            CXSourceLocation tl = clang_getTokenLocation(tu, tokens[i]);

            clang_getFileLocation(tl, &file, &line, &column, &offset);

            std::cout << "line: " << line
                << " column: " << column
                << " token: " << token
                << " color: " << sh->m_highlightMap[clang_getTokenKind(tokens[i])];
//            mw->highlightText(line, column, token.size(),
//                              clang_getTokenKind(tokens[i]));
        }
    }


    return CXChildVisit_Continue;
}

void SyntaxHighlighter::test() {
    const char* sourceFilename = "/some/path/file.cpp";
    const char* commandLineArgs[] = {"-c", "-x", "c++"};
    int numCommandLineArgs = 3;
    m_index = clang_createIndex(0, 0);
    m_translationUnit = clang_parseTranslationUnit(m_index, sourceFilename, commandLineArgs, numCommandLineArgs, 0, 0, CXTranslationUnit_None);

    CXCursor cursor = clang_getTranslationUnitCursor(m_translationUnit);
    clang_visitChildren(cursor, visitor, this);
}

