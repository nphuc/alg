open I,"lastdig2.c";
@a=<I>;
grep{
$_=~s/\s{2,}/ /g;
$_=~s/;\s+/;/g;
$_=~s/\{\s+/\{/g;
$_=~s/\}\s+/\}/g;
$_=~s/\[\s+/\[/g;
$_=~s/\]\s+/\]/g;
$_=~s/\(\s+/\(/g;
$_=~s/\)\s+/\)/g;
$_=~s/\s+;/;/g;
$_=~s/\s+\{/\{/g;
$_=~s/\s+\}/\}/g;
$_=~s/\s+\[/\[/g;
$_=~s/\s+\]/\]/g;
$_=~s/\s+\(/\(/g;
$_=~s/\s+\)/\)/g;}@a;

open O,">lastdig2.1.c";
for my$line(@a){
    print O $line;
    print $line;
}
close I;
close O;
