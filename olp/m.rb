def gt(n)
  s=1
  1.upto(n) do|i|
    s*=i
  end
  return s
end

def bsearch(a,v)
  st=0
  nd=a.length-1

  while(st<=nd)
    m=(st+nd)/2
    if v==a[m] then 
      return m
    elsif v<a[m] then
      nd=m-1
    else
      st=m+1
    end
  end
  return -1
end

def isprime(n)
  2.upto(Math.sqrt(n).to_i) do |i|
    if n %i==0 then 
      return 0
    end
  end
  return 1
end
