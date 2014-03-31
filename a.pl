open F,"cprime.out";
@a=<F>;
@o1=();@o2=();
while($#a>0){
    $l1=shift @a;
    if($l1=~/(\d+)/){
        push @o1,$1;
    }
    $l2=shift @a;
    if($l2=~/(\d+)/){
        push @o2,$1;
    }
}
open O1,">c1.out";
open O2,">c2.out";
for my $n(@o1){
    print O1 "$n,";
}
for my $n(@o2){
    print O2 "$n,";
}
close O1;
close O2;
