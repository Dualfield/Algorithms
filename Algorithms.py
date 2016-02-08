﻿import os
import re
import codecs
text='\
\\documentclass{book}\n\
\\usepackage{listings}\n\
\\usepackage{xcolor}\n\
\\usepackage{fontspec}\n\
\\usepackage{xeCJK}\n\
\\usepackage[Sonny]{fncychap}\n\
\\usepackage{titlesec}\n\
\\definecolor{javared}{rgb}{0.6,0,0}\n\
\\definecolor{javagreen}{rgb}{0.25,0.5,0.35}\n\
\\definecolor{javapurple}{rgb}{0.5,0,0.35}\n\
\\definecolor{javadocblue}{rgb}{0.25,0.35,0.75}\n\
\\titleformat*{\\section}{\\centering\\LARGE}\n\
\\newfontfamily{\\consolas}{Consolas}\n\
\\setmainfont{Gentium Book Basic}\n\
\\lstdefinelanguage{Vim}{keywords={let,set}}\n\
\\lstset{\n\
    frame=shadowbox,\n\
    framerule=0.5pt,\n\
    stringstyle=\\color{javared},\n\
    commentstyle=\\color{javagreen},\n\
    breaklines=true,\n\
    numbers=left,\n\
    columns=fullflexible,\n\
    showstringspaces=false,\n\
    aboveskip=1em,\n\
    keywordstyle=\\color{javapurple}\\bfseries,\n\
    basicstyle=\\consolas,\n\
    rulecolor=\\color{black}}\n\
\\usepackage{wallpaper}\n\
\\usepackage[b5paper,left=1.5cm,right=1.5cm]{geometry}\n\
\\usepackage[colorlinks,linkcolor=black]{hyperref}\n\
\\usepackage{bookmark}\n\
\\usepackage{emptypage}\n\
\\makeatletter\n\
\\newcommand{\\lst@invisiblevisiblespace}{%\n\
    \\textcolor{white}{\\lst@bkgcolor{\\lst@visiblespace}}}%\n\
\\AtBeginDocument{\n\
    \\let\\lst@newlineold@ProcessSpace\\lst@ProcessSpace\n\
    \\let\\lst@newlineold@ProcessTabulator\\lst@ProcessTabulator\n\
    \\let\\lst@newlineold@Append\\lst@Append}\n\
\\newcommand*{\\lst@beginline}{\n\
    \\lst@ifdisplaystyle\n\
        \\let\\lst@ProcessSpace\\lst@newline@ProcessSpace\n\
        \\let\\lst@ProcessTabulator\\lst@newline@ProcessTabulator\n\
        \\let\\lst@Append\\lst@newline@Append\n\
    \\fi}\n\
\\lst@AddToHook{EOL}{\\lst@beginline}\n\
\\newcommand*{\\lst@newline@ProcessSpace}{%\n\
    \\lst@PrintToken\n\
    \\lst@whitespacetrue\n\
    \\lst@AppendOther\\lst@invisiblevisiblespace\n\
    \\lst@PrintToken}\n\
\\newcommand*{\\lst@newline@ProcessTabulator}{%\n\
    \\@tempcnta=\\lst@tabsize\\relax\n\
    \\loop\n\
    \\ifnum\\@tempcnta>\\z@\n\
        \\lst@newline@ProcessSpace\n\
        \\advance\\@tempcnta\\m@ne\n\
    \\repeat}\n\
\\newcommand*{\\lst@newline@Append}[1]{%\n\
    \\ifx#1\\lst@invisiblevisiblespace\n\
    \\else\n\
        \\let\\lst@Append\\lst@newlineold@Append\n\
        \\let\\lst@ProcessSpace\\lst@newlineold@ProcessSpace\n\
        \\let\\lst@ProcessTabulator\\lst@newlineold@ProcessTabulator\n\
    \\fi\n\
    \\lst@newlineold@Append{#1}}\n\
\\lst@AddToHook{Init}{\\lst@beginline}\n\
\\makeatother\n\
\\begin{document}\n\
\\thispagestyle{empty}\n\
{\\huge{\\rightline{\\textbf{Algorithms}}}}\n\
\\newpage\n\
\\thispagestyle{empty}\n\
\\begin{center}\n\
\\vspace*{\\fill}\n\
        \\textbf{Algorithms} by Yu Dongfeng\n\
\n\
        First version on November 28, 2015\n\
\n\
        Latest version on \\today\n\
        \\vspace*{\\fill}\n\
\\end{center}\n\
\\newpage\n\
\\setcounter{page}{1}\n\
\\pdfbookmark[section]{\\contentsname}{toc}\n\
\\tableofcontents\n\
\\newpage\n'
for i in os.listdir():
    if os.path.isdir(i)and i!='.git':
        text+='\
\\chapter{'+i+'}\n\
\\newpage\n'
        os.chdir(i)
        for j in os.listdir():
            text+='\
\\addtocontents{toc}{}\n\
\\section{'+j.split('.')[0]+'}\n\\noindent '+j+'\n\
\\begin{lstlisting}[language=C++]\n'
            text+=codecs.open(j,'r','utf-8').read()
            text+='\
\\end{lstlisting}\n'
        os.chdir(os.pardir)
codecs.open('Algorithms.tex','w','utf-8').write(text+'\\end{document}\n')
for i in range(2):
    os.system('xelatex Algorithms.tex')
for i in os.listdir():
    if i[:11]=='Algorithms.' and i[11:]!='py' and i[11:]!='pdf':
        os.remove(i)