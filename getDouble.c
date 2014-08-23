inline double getDouble() {
  double res = 0.0;
  char c;
  while(1) {
    c = getchar_unlocked();
    if(c == ' ' || c == '\n') continue;
    else break;
  }
  res = c - '0';
  while(1) {
    c = getchar_unlocked();
    if(c >= '0' && c <= '9') res = 10 * res + c - '0';
    else break;
  }
  if(c == '.') {
    double decimal = 0.0, divi = 1.0;
    while(1) {
      c = getchar_unlocked();
      if(c >= '0' && c <= '9') decimal += (c - '0') / (divi *= 10.0);
      else break;
    }
    res += decimal;
  }
  return res;
}
