my ($a,$b)=split/ +/,<>;
my $t1=20000,$t2=2990000,$t3=497990000;
sub money{
  my $w=shift;
  if($w<=100) {return $w*200;}
  if($w<=10000) {return $t1+($w-100)*300;}
  if($w<=1000000) {return $t2+($w-10000)*500;}
  return $t3+($w-1000000)*700;
}
sub kwh{
  my $m=shift;
  if($m<= $t1){ return $m/200;}
  if($m<=$t2){ return ($m-$t1)/300+100;}
  if($m<=$t3){ return ($m-$t2)/500+10000;}
  return ($m-$t3)/700+1000000;
}
sub d2{
  my ($a,$b,$c,$d)=@_;
  return $a*$d-$b*$c;
}
sub he2an{
  my ($a1,$b1,$c1,$a2,$b2,$c2)=@_;
  my $dd=d2 $a1,$b1,$a2,$b2;
  my $dx=d2 $c1,$b1,$c2,$b2;
  my $dy=d2 $a1,$c1,$a2,$c2;
  return ($dx/$dd,$dy/$dd);
}
my $s=kwh $a;
my $c1=100*300-$t1;
my $c2=10000*500-$t2;
my $c3=1000000*700-$t3;
my ($x,$y)=he2an(1,1,$s,-200,200,$b);
if($x>0 && $y>0) { print money $x; exit 0;}
my ($x,$y)=he2an(1,1,$s,-300,300,$b);
if($x>0  and  $y>0) { print money $x; exit 0;}
my ($x,$y)=he2an(1,1,$s,-500,500,$b);
if($x>0  and  $y>0) { print money $x; exit 0;}
my ($x,$y)=he2an(1,1,$s,-700,700,$b);
if($x>0  and  $y>0) { print money $x; exit 0;}

my ($x,$y)=he2an(1,1,$s,-200,300,$b+$c1);
if($x>0  and  $y>0) { print money $x; exit 0;}
my ($x,$y)=he2an(1,1,$s,-200,500,$b+$c2);
if($x>0  and  $y>0) { print money $x; exit 0;}
my ($x,$y)=he2an(1,1,$s,-200,700,$b+$c3);
if($x>0  and  $y>0) { print money $x; exit 0;}
my ($x,$y)=he2an(1,1,$s,-300,500,$b+$c2-$c1);
if($x>0  and  $y>0) { print money $x; exit 0;}
my ($x,$y)=he2an(1,1,$s,-300,700,$b+$c3-$c1);
if($x>0  and  $y>0) { print money $x; exit 0;}
my ($x,$y)=he2an(1,1,$s,-500,700,$b+$c3-$c2);
if($x>0  and  $y>0) { print money $x; exit 0;}
