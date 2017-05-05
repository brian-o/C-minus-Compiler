int f(int x, int y){
    write x;
    write y;
}

int ret42(void){
    return 42;
}

int doubleit(int a){
    return 2*a;
}

int on;
int off[5];

void main(void){
    int a;
    int b[10];
    b[0] = 10;
    b[1] = 11;
    b[2] = 22;
    b[3] = 33;
    b[4] = 44;
    b[5] = 55;
    b[6] = 66;
    b[7] = 77;
    b[8] = 88;
    b[9] = 99;
    a = 5;
    f(a,9);
    a = 3;
    f(a,f(6,9));
    a = ret42();
    write a;
    a = doubleit(a);
    write a;
    write doubleit(a);
    on = ret42();
    write on;
    on = on - b[0]-b[1];
    write on;
    write on<42;
    write on>42;
    on = 0;
    if (on == 0)
        write 123;
    else
        write 456;
    a = 10;
    while (a>=0){
        write a;
        a = a-1;
    }
    while (a<=b[5]/5){
        write a;
        a = a+b[0]/10;
    }

}
