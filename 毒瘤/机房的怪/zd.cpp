#include "ai"
int rad(){
	return 1<<rand()^rand();
}
void go(Gen own,Gen enemy,int&a,int&b,int&c){
	int k=0;
	for (int i=1;i<3;++i) if (enemy.cards[i].dps+enemy.cards[i].hp/10>enemy.cards[k].dps+enemy.cards[k].hp/10) k=i;
	a=b=c=k;
	if (rad()%4==0){
		if (rad()%3==0) a=rad()%3;
		else if (rad()%2==0) b=rad()%3;
		else c=rad()%3;
	}
	return;
}
