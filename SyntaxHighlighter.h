//
// Created by saxcell on 1/15/19.
//

#ifndef CLANG_SYNTAX_HIGHLIGHTER_SYNTAXHIGHLIGHTER_H
#define CLANG_SYNTAX_HIGHLIGHTER_SYNTAXHIGHLIGHTER_H

#include <string>
#include <clang-c/Index.h>
#include <map>

class SyntaxHighlighter {
public:
    SyntaxHighlighter();
    ~SyntaxHighlighter();

    std::string getCurrentFile();
    void test();

//private:
    CXIndex m_index;
    CXTranslationUnit m_translationUnit;

    std::map<CXTokenKind, std::string> m_highlightMap;
};

// must be static
CXChildVisitResult visitor(CXCursor cursor, CXCursor parent, CXClientData clientData);

#endif //CLANG_SYNTAX_HIGHLIGHTER_SYNTAXHIGHLIGHTER_H
