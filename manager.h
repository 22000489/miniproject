#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[50]; // 제품 이름
    char tag[100]; // 제품 설명
    char weight[20]; // 제품 중량
    int cost, way; // 판매 가격, 배송 방법
    int order; // 제품 번호
} Product;

int selectMenu();

int deleteProduct(Product *p[], int count); // 제품을 삭제하는 함수

int updateProduct(Product *p[]); // 제품을 수정하는 함수

int createProduct(Product *p[], int count); // 제품을 추가하는 함수

void readProduct(Product *p[], int count); // 하나의 제품 출력 함수

void listProduct(Product *p[], int count); // 전체 등록된 제품 리스트 출력

void saveFile(Product *p[], int count); // 파일 저장

int loadData(Product *p[]); // 파일 불러오기
