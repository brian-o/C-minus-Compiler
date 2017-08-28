int sum(int x){
  if(x>0)
    return x + sum(x-1);
  return 0;
}

int show(int a){
  write a;
}
int main(void){
  write sum(5);
  show(42);
}