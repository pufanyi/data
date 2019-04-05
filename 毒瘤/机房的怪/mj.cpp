#include "ai"
void go(Gen own,Gen enemy,int&a,int&b,int&c){
	for(int i=0;i<3;i++)if(enemy.cards[i].name=="gj"){
		a=b=c=i;
		return;
	}
	a=0;
	b=1;
	c=2;
}
