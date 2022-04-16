#include "manager.h"

int main(void){
#ifdef DEBUG
	printf("=> DEBUGMODE\n");
#endif
    int count = 0, menu;
    Product *p[20];
    count = loadData(p);
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if ((menu==1) || (menu == 3) || (menu == 4))
            if(count == 0) {
                continue;
            }
        if (menu == 1){
            listProduct(p, count);
        }
        else if (menu == 2){
            if(createProduct(p, count) == 1){
            count++;
            printf("추가됨!\n");
            }
            continue;
        }
        else if (menu == 3){
            listProduct(p, count);
            if(updateProduct(p) == 1)
            printf("=> 수정됨!\n");
        }
        else if (menu == 4){
            if(deleteProduct(p, count) == 1){
            count--;
            printf("=>삭제됨!\n");
        }
        }
        else if (menu == 5){
            saveFile(p, count);
        }
	else if(menu == 6)
            searchName(p, count);
        
	else if(menu == 7)
            searchWay(p, count);
        
	else if(menu == 8)
            searchCost(p, count);

        else if(menu == 9)
            readProduct(p, count);
    }
    printf("종료됨!\n");
    return 0;
}

