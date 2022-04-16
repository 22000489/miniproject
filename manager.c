#include "manager.h"

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("9. 단일제품조회\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createProduct(Product *p[], int count){
    p[count] = malloc(sizeof(Product));
    getchar();
    printf("제품명은? ");
    scanf("%[^\n]s", p[count]->name);
    getchar();
    printf("제품설명은? ");
    scanf("%[^\n]s", p[count]->tag);
    getchar();
    printf("제품중량은? ");
    scanf("%[^\n]s", p[count]->weight);
    getchar();
    printf("판매가격은? ");
    scanf("%d", &p[count]->cost);
    printf("배송방법은? ");
    scanf("%d", &p[count]->way);
    p[count]->order = count+1;
    return 1;
} // 제품 추가 함수

int deleteProduct(Product *p[], int count){
    listProduct(p, count);
    int num, flag;
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &num);
    int j = num;
    if(num == 0)
    printf("삭제가 취소되었습니다");
    else{
    printf("정말로 삭제하시겠습니까?(삭제 :1)");
    scanf("%d", &flag);    
    if(flag == 1){
        for(int i=num-1; i<count-1; i++){
        strcpy(p[i]->name,p[j]->name);
        strcpy(p[i]->tag,p[j]->tag);
        strcpy(p[i]->weight,p[j]->weight);
        p[i]->cost  = p[j]->cost;
        p[i]->way = p[j]->way;
        p[i]->order = p[j]->order;
        j++;
        }
        return 1;
        }
    else 
        printf("삭제가 취소되었습니다.");
    }
    return 0;
}       // 제품을 삭제하는 함수

int updateProduct(Product *p[]){
    int num;
    printf("제품 번호는?");
    scanf("%d", &num);
    printf("제품명은? ");
    getchar();
    scanf("%[^\n]s", p[num-1]->name);
    getchar();
    printf("제품설명은? ");
    scanf("%[^\n]s", p[num-1]->tag);
    getchar();
    printf("제품중량은? ");
    scanf("%s", p[num-1]->weight);
    // getchar();
    printf("판매가격은? ");
    scanf("%d", &p[num-1]->cost);
    printf("배송방법은? ");
    scanf("%d", &p[num-1]->way);

    return 1;
}       // 제품을 수정하는 함수

void readProduct(Product *p[], int count){
    int num;
    listProduct(p, count);
    printf("\n원하는 제품의 번호는? ");
    scanf("%d", &num);
    printf("%d 제품 설명 : %s\n", p[num-1]-> order, p[num-1]->tag);
    
} // 하나의 제품 출력 함수

void listProduct(Product *p[], int count){
printf("No 제품명       중량  판매가격  배송방법\n");
    printf("===============================================\n");
    for(int i=0; i<count; i++){
        if(p[i]->order == 0)break;
    printf("%d %2s %3s      %6d %6d\n", p[i]->order, p[i]-> name, p[i]-> weight, p[i]-> cost, p[i]-> way);
    }
} // 전체 등록된 제품 리스트 출력

int loadData(Product *p[]){
    int i=0;
    int num;
    FILE *fp;
    fp = fopen("product.txt", "rt");
    if(fp == NULL){
        printf("=> 파일 없음\n");
	return 0;
    }
    else{
    while(1){
        if(feof(fp))break;
        p[i] = malloc(sizeof(Product));
        fflush(stdin);
        fscanf(fp, "%d %[^\n]s", &p[i]->order, p[i]->name);
        fflush(stdin);
        fscanf(fp, "%s", p[i]->weight);
        fscanf(fp, "%d", &p[i]->cost);
        fscanf(fp, "%d", &p[i]->way);
        fflush(stdin);
        fscanf(fp, "%[^:]s", p[i]->tag);
        fscanf(fp,"%d",&num);
        fscanf(fp,":");
        i++;
    }
    printf("=>로딩 성공!\n");
    }
    fclose(fp);
    return i;
}

