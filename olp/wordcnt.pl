my @lines=<>;
my $test=$lines[0];
sub solve{
  my $line=shift;
  my @w=split /\s+/,$line;
  my $prevcnt=0,$same=1,$res=0;
  for(my $i=0;$i<=$#w+1;++$i){
    my $len=length $w[$i];
    if($len== $prevcnt){
      ++$same;
    }else{
      $prevcnt=$len;
      #print "same =$same \n";
      if($same> $res) { $res=$same;}
      $same=1;
    }
  }
  return $res;
}
for(my $i=0;$i<$test;++$i){
  print solve $lines[$i+1];
  print "\n";
}
