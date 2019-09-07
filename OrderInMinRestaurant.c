/*
제목: The Min Restaurant 이용법
기능: The Min Restaurant의 메뉴, 할인, 이벤트, 예약 알아보기
소스파일: OrderInTheRestaurant / OrderInMinRestarant.c
만든날짜: 2018.05.29
작성자 학번 이름: 20166450 김영민
버전: V.15.5.7. 2017
*/

#include <stdio.h>


int main(void)
{
	int num1, num2, num3;

	puts("");
	//민레스토랑에 관한 인삿말입니다
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("               Thanks for visiting to The Min Restaurant <3        \n");
	printf("                         Enjoy whatever you want                   \n");
	printf("                     We're not going to let you down               \n");
	printf("___________________________________________________________________\n");
	
	puts("");
	puts("");

	//레스토랑에 기본적인 메뉴판입니다.
	printf("-------------------------------메뉴판-------------------------------\n");
	puts("");
	printf("        메인메뉴,사이드메뉴,음료 주문시 각세트당 가격순으로 10%% 할인    \n");
	printf("                       모든메뉴 중복할인 불가★                       \n");
	puts(""); 
	printf("                          1)  MAIN DISHES                           \n");
	printf("                        봉골레파스타   9000원                        \n");
	printf("                        로제파스타    10000원                        \n");
	printf("                        크림파스타    11000원                        \n");
	puts("");  
	printf("                          2)  SIDE DISHES                           \n");
	printf("                        크림샐러드     5000원                        \n");
	printf("                        계란토마토     6000원                        \n");
	printf("                        튀김퐁듀       4000원                        \n");
	puts("");
	printf("                          3)  Beverage                              \n");
	printf("                        자몽에이드     4000원                        \n");
	printf("                        체리에이드     4000원                        \n");
	printf("                        콜라,사이다    2000원                        \n");
	puts("");
	printf("--------------------------------------------------------------------\n");
	puts("");
	puts("");


	//안에 스위치 문에서 4번을 선택한 것이 아니라면 다시 실행 되도록 so while을 설정해줍니다.
	do
	{
		//이 프로그랩에서 가장 기본이 되는 큰 보기입니다.
		printf("-----------------------------[MENU]-----------------------------\n");
		printf("                           1. 길찾기                             \n");
		printf("                           2. 주문하기(할인적용)                  \n");
		printf("                           3. 예약하기                           \n");
		printf("                           4. 나가기                             \n");
		printf("-----------------------------------------------------------------\n");
		puts("");
		printf("Enter:");
		scanf("%d", &num1);
		switch (num1)
		{
		//길찾기
		case 1:

			//지도처럼 볼 수 있도록 구현하였습니다.
			printf("----------------------------------<길찾기>-------------------------------------\n");
			puts("");
			printf("        _________________________________________________________________     \n");
			printf("           __________      ___________              건대역2번출구              \n");
			printf("          |          |    |           |                  ↓                    \n");
			printf("          |  Emart   |    |    GS25   |   |||||||||||||                       \n");
			printf("          |__________|    |___________|                                       \n");
			printf("                                                                              \n");
			printf("           ___________________           ______________                       \n");
			printf("          |                   |         |              |                      \n");
			printf("          |   Min Restaurant  |         |  OliveYoung  |                      \n");
			printf("          |___________________|         |______________|                      \n");
			printf("                                                                              \n");
			printf("         _______________________________________________________________      \n");
			puts("");
			printf("              설명: 건대입구역 2번출구-> GS25지나 왼쪽건물 (지도참고)");
			puts("");
			printf("------------------------------------------------------------------------------\n");
			puts("");
			puts("");
			puts("");
			printf("도움말: 다른 메뉴를 다시 선택하거나 끝내려면 4번 나가기를 선택해주세요\n");

			break;
		
		//주문하기
		case 2:
			puts("");
			puts("");
			
			    //여러가지 할인을 받을 수 있도록 설정하였습니다
				printf("---------------------------------[주문하기]------------------------------\n");
				puts("");
				printf("                   1. 세트 할인 (쿠폰과 소수데이가 아닐경우 선택)           \n");
				printf("                   2. 할인 쿠폰 소지시                                    \n");
				printf("                   3. 소수(Prime number)데이 할인                         \n");
				puts("");
				printf("                주의사항 : 위 보기 중 한가지만 선택, 중복할인불가           \n");
				puts("");
				printf("-------------------------------------------------------------------------\n");

			//이번에는 1,2,3번이 아니라면 스위치문이 다시 실행되도록 설정하였습니다
			do 
			{
				printf("Enter:");
				scanf("%d", &num2);
				switch (num2)
				{
				case 1:
					puts("");

					int i, j, z, tmp = 0, cnt = 0, total1 = 0, total = 0;
					int a[1000], b[1000], c[1000], dcnt[1000], x[3];

					//세트할인을 어떠한 룰로 받을 수 있는 지 설명되어 있습니다.
					printf("_____________________________[세트 할인 설명]_____________________________\n");
					printf("                                                                         \n");
					printf("                      메인메뉴, 사이드메뉴, 음료메뉴                        \n");
					printf("                     각 1개씩 총 3개가 1세트를 이루어                       \n");
					printf("                        10%% 할인을 받을 수 있다.                          \n");
					printf("                                                                         \n");
					printf("                       세트 구성은 주문한 메뉴들 중에                       \n");
					printf("                       가격이 높은 순으로 짝을 이룬다.                      \n");
					printf("                     세트가 안되는 메뉴들은 할인 적용x                      \n");
					printf("                                                                         \n");
					printf("_________________________________________________________________________\n");

					puts("");
					puts("");
					
					//개수를 입력하는 부분인데 이는 세트가 몇세트있는지 판별하는데 쓰입니다.
					printf("맨 위 메뉴판을 참고하여 \n");
					printf("주문할 메인메뉴'개수' 사이드메뉴'개수' 음료'개수'들을 공백을 두고 입력하세요\n");
					for (i = 0; i < 3; i++)
						scanf("%d", &x[i]);

					puts("");
					printf("맨 위 메뉴판을 참고하여 \n");
					printf("주문할 메인메뉴의 각각의 '가격'을 공백을 두고 입력하세요\n");
					for (i = 0; i < x[0]; i++)
						scanf("%d", &a[i]);

					puts("");
					printf("맨 위 메뉴판을 참고하여 \n");
					printf("주문할 사이드메뉴의 각각의 '가격'을 공백을 두고 입력하세요\n");
					for (j = 0; j < x[1]; j++)
						scanf("%d", &b[j]);

					puts("");
					printf("맨위 메뉴판을 참고하여 \n");
					printf("주문할 음료의 각각의 '가격'을 공백을 두고 입력하세요\n");
					for (z = 0; z < x[2]; z++)
						scanf("%d", &c[z]);


					//메인메뉴들의 가격들을 높은 가격순으로 정렬하는 식입니다.
					for (i = 0; i < x[0]; i++)
					{
						for (j = i + 1; j < x[0]; j++)
							if (a[i] < a[j])
							{
								tmp = a[i];
								a[i] = a[j];
								a[j] = tmp;
							}
					}

					//사이드 메뉴를 정렬하는 코드입니다.
					for (i = 0; i < x[1]; i++)
					{
						for (j = i + 1; j < x[1]; j++)
							if (b[i] < b[j])
							{
								tmp = b[i];
								b[i] = b[j];
								b[j] = tmp;
							}
					}

					//음료메뉴를 정렬하는 식입니다.
					for (i = 0; i < x[2]; i++)
					{
						for (j = i + 1; j < x[2]; j++)
							if (c[i] < c[j])
							{
								tmp = c[i];
								c[i] = c[j];
								c[j] = tmp;
							}
					}
					
					//이는 최소한으로 나올 수 있는 세트가 몇개인지 비교연산자를 통해 cnt에 저장합니다.
					cnt = ((x[0] < x[1] ? x[0] : x[1]) < x[2] ? (x[0] < x[1] ? x[0] : x[1]) : x[2]);

					//10% 할인된 세트들의 가격을 변수에 저장합니다.
					for (i = 0; i < cnt; i++)
						total += (a[i] + b[i] + c[i])*0.9;

					//나머지 할인 받지 못한 메뉴들의 가격들을 그대로 더해줍니다.
					if (cnt < x[0])
					{
						for (j = cnt; j < x[0]; j++)
							total += a[j];
					}
					if (cnt < x[1])
					{
						for (j = cnt; j < x[1]; j++)
							total += b[j];
					}
					if (cnt < x[2])
					{
						for (j = cnt; j < x[2]; j++)
							total += c[j];
					}

					puts("");
					printf("할인된 합산 총 가격: %d원 \n", total);

					break;

				case 2:

					puts("");
					printf(" -----------------------------<보기1>---------------------------\n");
					puts("");
					printf("                      1- 빨간색 쿠폰 40%% 할인                   \n");
					printf("                      2- 파란색 쿠폰 30%% 할인                   \n");
					printf("                      3- 노란색 쿠폰 20%% 할인                   \n");
					printf("                      4- 흰색   쿠폰 10%% 할인                   \n");
					puts("");
					printf("                           중복사용 불가능                       \n");
					puts("");
					printf(" ---------------------------------------------------------------\n");
					puts("");

					int color;

					printf("소지하신 쿠폰의 색깔은 무슨색입니까? (보기의 번호로 입력하시오)\n");
					printf("입력: ");
					scanf("%d", &color);
					puts("");
					puts("");
					
					printf(" ---------------------------<보기2>---------------------------\n");
					puts("");
					printf("                      (1)  봉골레파스타                        \n");
					printf("                      (2)  로제파스타                          \n");
					printf("                      (3)  크림파스타                          \n");
					printf("                      (4)  크림샐러드                          \n");
					printf("                      (5)  계란토마토                          \n");
					printf("                      (6)  튀김퐁듀                            \n");
					printf("                      (7)  자몽에이드                          \n");
					printf("                      (8)  체리에이드                          \n");
					printf("                      (9)  콜라                                \n");
					printf("                      (10) 사이다                              \n");
					printf("                      (11) 주문완료                            \n");
					puts("");
					printf("                 주문할 메뉴의 번호를 입력하세요                 \n");
					printf("              (반복입력가능, 주문완료시 11번 선택)               \n");
					printf(" --------------------------------------------------------------\n");

					int d[10];
					int sum1=0, sum2=0;
					for (i = 0; i < 10; i++)
						d[i] = 0;

					// 주문할 메뉴를 번호로 선택하고 개수를 입력하기를 반복할수 있도록 do while 스위치 문을 이용해 줍니다.
					do
					{
						printf("Enter:");
						scanf("%d", &num3);

						switch (num3)
						{
						case 1:
							printf("봉골레파스타 개수: ");
							scanf("%d", &d[0]);
							sum1 += 9000*d[0];
							break;

						case 2:
							printf("로제파스타 개수: ");
							scanf("%d", &d[1]);
							sum1 += 10000*d[1];
							break;

						case 3:

							printf("크림파스타 개수: ");
							scanf("%d", &d[2]);
							sum1 += 11000*d[2];
							break;

						case 4:
							printf("크림샐러드 개수: ");
							scanf("%d", &d[3]);
							sum1 += 5000*d[3];
							break;

						case 5:
							printf("계란토마토 개수: ");
							scanf("%d", &d[4]);
							sum1 += 6000*d[4];
							break;

						case 6:
							printf("튀김퐁듀 개수: ");
							scanf("%d", &d[5]);
							sum1 += 4000*d[5];
							break;

						case 7:
							printf("자몽에이드 개수: ");
							scanf("%d", &d[6]);
							sum1 += 4000*d[6];
							break;

						case 8:
							printf("체리에이드 개수: ");
							scanf("%d", &d[7]);
							sum1 += 4000*d[7];
							break;

						case 9:
							printf("콜라 개수: ");
							scanf("%d", &d[8]);
							sum1 += 2000*d[8];
							break;

						case 10:
							printf("사이다 개수: ");
							scanf("%d", &d[9]);
							sum1 += 2000*d[9];
							break;

						case 11:
							break;
						}
					} while (num3 != 11);
					
					puts("");
					printf("할인전 가격: %d원\n", sum1);
					puts("");
					printf("쿠폰 할인 적용시 총가격:");

					//if-else문을 이용하여 각 쿠폰마다 적용되는 할인율을 구현해 줍니다.
					if (color == 1)
						sum2 = sum1 * 0.6;
					else if (color == 2)
						sum2 = sum1 * 0.7;
					else if (color == 3)
						sum2 = sum1 * 0.8;
					else
						sum2 = sum1 * 0.9;

					printf(" %d원 \n",sum2);

					break;

				case 3:

					//예시로 31일 중에 소수인 날짜들을 출력해주는 PrimeNumber 출력하기를 이용하였습니다.
					printf("1~31일 중 할인 되는 날짜:");
					int x3, y3, sum4 = 0, n = 31, data3,sum5=0;
					for (x3 = 2; x3 <= n; x3++)
					{
						for (y3 = 1; y3 <= x3; y3++)  
						{
							if (x3 % y3 == 0)
								sum4 += 1;            
						}
						if (sum4 == 2)                
							printf("%d일 ", x3);
						sum4 = 0;
					}
					puts("");
					printf("                                                                 \n");

					//예약할 날짜를 입력받고 그 값이 소수인지 아닌지 판별하는 식을 for,if문으로 구현하였습니다.
					printf("예약할날짜가 무슨 日인지 입력하세요 (숫자만입력):                          \n");
					scanf("%d",&data3);
					for (y3 = 1; y3 <= data3; y3++)  
					{
						if (data3 % y3 == 0)
							sum5 += 1;            
					}

					//만약 소수데이가 맞다면 이 구문을 실행합니다.
					if (sum5 == 2)
					{
						puts("");
						printf("입력하신 날짜는 소수데이임으로 할인을 받으실 수 있습니다. \n");
						puts("");
						printf(" ---------------------------<보기2>---------------------------\n");
						puts("");
						printf("                      (1)  봉골레파스타                        \n");
						printf("                      (2)  로제파스타                          \n");
						printf("                      (3)  크림파스타                          \n");
						printf("                      (4)  크림샐러드                          \n");
						printf("                      (5)  계란토마토                          \n");
						printf("                      (6)  튀김퐁듀                            \n");
						printf("                      (7)  자몽에이드                          \n");
						printf("                      (8)  체리에이드                          \n");
						printf("                      (9)  콜라                                \n");
						printf("                      (10) 사이다                              \n");
						printf("                      (11) 주문완료                            \n");
						puts("");
						printf("                 주문할 메뉴의 번호를 입력하세요                 \n");
						printf("              (반복입력가능, 주문완료시 11번 선택)               \n");
						printf(" --------------------------------------------------------------\n");

						int d[10];
						int sum1 = 0, sum2 = 0;
						for (i = 0; i < 10; i++)
							d[i] = 0;

						do
						{
							printf("Enter:");
							scanf("%d", &num3);

							switch (num3)
							{
							// 각 가격에서 -1000원이 할인 된 가격을 곱해줍니다.
							case 1:
								printf("봉골레파스타 개수: ");
								scanf("%d", &d[0]);
								sum1 += 8000 * d[0];
								break;

							case 2:
								printf("로제파스타 개수: ");
								scanf("%d", &d[1]);
								sum1 += 9000 * d[1];
								break;

							case 3:

								printf("크림파스타 개수: ");
								scanf("%d", &d[2]);
								sum1 += 10000 * d[2];
								break;

							case 4:
								printf("크림샐러드 개수: ");
								scanf("%d", &d[3]);
								sum1 += 4000 * d[3];
								break;

							case 5:
								printf("계란토마토 개수: ");
								scanf("%d", &d[4]);
								sum1 += 5000 * d[4];
								break;

							case 6:
								printf("튀김퐁듀 개수: ");
								scanf("%d", &d[5]);
								sum1 += 3000 * d[5];
								break;

							case 7:
								printf("자몽에이드 개수: ");
								scanf("%d", &d[6]);
								sum1 += 3000 * d[6];
								break;

							case 8:
								printf("체리에이드 개수: ");
								scanf("%d", &d[7]);
								sum1 += 3000 * d[7];
								break;

							case 9:
								printf("콜라 개수: ");
								scanf("%d", &d[8]);
								sum1 += 1000 * d[8];
								break;

							case 10:
								printf("사이다 개수: ");
								scanf("%d", &d[9]);
								sum1 += 1000 * d[9];
								break;

							case 11:
								break;
							}
						} while (num3 != 11);

						puts("");
						printf("할인 적용시 주문한 메뉴들의 총 가격: %d", sum1);
					}

					//만약 소수데이가 아니라면 할인이 적용되지 않는다는 구문을 출력합니다.
					else
					{
						puts("");

						printf("예약할 날짜가 소수데이가 아니므로 할인이 적용되지 않습니다.\n");
					}
					printf("                                                                 \n");
					printf("                                                                 \n");
					break;
				}
			} while ((num2 != 1 && num2 != 2)&& num2 !=3);
			puts("");
			printf("다른 메뉴를 다시 선택하거나 끝내려면 4번 나가기를 선택해주세요 \n");
			break;
		

		case 3:
			printf(" ---------------------------<예약날짜선택>-------------------------\n");
			puts("");
			printf("           참고: 오늘로부터 7일이내까지만 예약할 수 있습니다.         \n");
			puts("");
			printf("                           1)  월요일(Mon)                         \n");
			printf("                           2)  화요일(Tue)                         \n");
			printf("                           3)  수요일(Wed)                         \n");
			printf("                           4)  목요일(Thu)                         \n");
			printf("                           5)  금요일(Fri)                         \n");
			printf("                           6)  토요일(Sat)                         \n");
			printf("                           7)  일요일(Sun)                         \n");
			printf("                                                                  \n");
			printf(" -----------------------------------------------------------------\n");

			int num4;

			//enum 데이타를 이용하여 각 요일에 번호를 부여합니다.
			enum Date{Mon=1,Tue, Wed,Thu,Fri,Sat,Sun};

				printf("Enter:");
				scanf("%d", &num4);
				puts("");

				//3중 스위치문을 설정하여 예약된 내용을 출력합니다.
				switch (num4)
				{
				case Mon:
					printf("월요일에 예약되셨습니다.\n");
					break;

				case Tue:
					printf("화요일에 예약되셨습니다.\n");
					break;

				case Wed:
					printf("수요일에 예약되셨습니다.\n");
					break;

				case Thu:
					printf("목요일에 예약되셨습니다.\n");
					break;

				case Fri:
					printf("금요일에 예약되셨습니다.\n");
					break;

				case Sat:
					printf("토요일에 예약되셨습니다.\n");
					break;

				case Sun:
					printf("일요일에 예약되셨습니다.\n");
					break;
				}
				puts("");
				printf("다른 메뉴를 다시 선택하거나 끝내려면 4번나가기를 선택해주세요 \n");
			break;

		default:
			puts("");
			printf("나가기를 선택하셨음로 종료합니다 \n");
			puts("");
		}
	} while (num1 != 4);


	return 0;
}