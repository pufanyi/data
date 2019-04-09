#include "ai"
void go(Gen own,Gen enemy,int&a,int&b,int&c){
	srand((unsigned)time(NULL));
	static int my[3];
	int k=0;
	for (int i=1;i<3;++i) if (enemy.cards[i].dps>enemy.cards[k].dps) k=i;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
				if(rand()%3)my[i]=j;
	}
	int hp=1e9;
	for(int i=0;i<3;i++)
		if(enemy.cards[i].hp<hp){
			hp=enemy.cards[i].hp;
			for(int j=0;j<3;j++)
				if(!my[j])my[j]=i;
		}
	a=my[0];b=my[1];c=my[2];
}
