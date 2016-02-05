:ag
gen > in.txt
p1 < in.txt > p1.txt
p2 < in.txt > p2.txt
fc p1.txt p2.txt
if errorlevel 1 pause
goto ag
