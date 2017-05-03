int a;
int bb[100];
int main(void){
    int c;
    int d;
    int e;
    int x[10];
    int y[20];
    a = 42;
    bb[42] = 66;
    c = 0;
    d = 1;
    x[1+2] = 99;
    write x[3];
    write a;
    write bb[400/10+(4*2-6)];
    if (c)
    write 101;
    else
    write 77;
    if (c<d)
    write 55;
    while (c<10){
        write c;
        c = c+1;
    }
    e = 0;
    while (e<10){
        if(e/2 >=2)
            write 40;
        else
            write 20;
        e = e+1;
    }
}
