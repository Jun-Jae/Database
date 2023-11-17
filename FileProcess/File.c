#include <stdio.h>
#include <stdlib.h>

struct person{
  // 도서목록 검색을 위한 구조체 선언
  char name[20]; // 이름
  char address[30]; // 주소
  int age; // 나이
};

struct person pi[5] = {

  {"Lim", "Seoul", 23},
  {"Lee", "Daejeon", 22},
  {"Park", "Jeju", 21},
  {"Choi", "Ulsan", 20},
  {"Kim", "Busan", 24}

};

int main()
{
  struct person po[5];
  FILE *fp; // 파일포인터 선언
  int i;
//파일 쓰기
  if((fp = fopen("BookMana.txt", "w")) == NULL)
  {    // 도서관리를 위한 파일 읽기
       // r -> 읽기모드(Read)
       // Stream 열기
      printf("Error: could not open BookMana.txt. Wn");
      exit(1);
  }
  fwrite(pi, sizeof(struct person), 5, fp);
  fclose(fp);
// 파일 읽기
  if((fp = fopen("BookMana.txt", "r")) == NULL)
  {
    printf("Error: could not open BookMana.txt. Wn");
    exit(1);
  }
  fread(po, sizeof(struct person), 5, fp);
  fclose(fp);
// 출력 부분
  printf("   : 이름       주소      나이\n");
  printf("================================\n");
  for(i = 0; i < 5; i++) 
    printf("%2d : %-10s%-10s%5d\n", i+1, po[i].name, po[i].address, po[i].age);

  return 0;
}
