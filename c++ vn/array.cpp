#include <cstdio>

int main(){
    //define variables
    const unsigned int n = 5; //viet vao day so phan tu cua mang
    int mang[n];
    int counter = 0; //dem so phan tu chan
    for(int i = 0; i < n; i++){
        //cout << i << ". phan tu: "; cin >> mang[i];
        printf("Nhap vao phan tu %d cua mang: ",i+1);
        scanf("%d", &mang[i]);
    }
    for(int i = 0; i < n; i++){
        printf("%d phan tu cua mang la: %d\n",i+1,mang[i]);
        if (mang[i]%2 == 0){
            counter++;
        }
    }
    if(counter == n){
        printf("\nTat ca deu la so chan!\n");
    }
    else if(counter == 0){
        printf("\nTat ca deu la so le!\n");
    }
    return 0;
}
