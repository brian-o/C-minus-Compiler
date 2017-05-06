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
int off2[5];

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
    f(2+2,2<3);
    a = 5;
    f(a,9);
    a = 12;
    f(a,f(9,f(3,6)));
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
    off[0] = 23;
    off[1] = 24;
    off[2] = 25;
    off[3] = 26;
    off[4] = 27;
    off2[0] = 34;
    off2[1] = 35;
    off2[2] = 36;
    off2[3] = 37;
    off2[4] = 38;
    
    write off[0];
    write off[1];
    write off[2];
    write off[3];
    write off[4];
    write off2[0];
    write off2[1];
    write off2[2];
    write off2[3];
    write off2[4];
}
