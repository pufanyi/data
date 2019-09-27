#include<string>
#include<cstdio>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std; 
#define cls system("cls")
string uu[12]={"奴隶制","封建制","资产阶级君主立宪制",
"帝国主义","总统制","社会主义","法西斯主义","联邦共和制","超级社会主义"};
string orz,z1,z2;
int ooo[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int sh[2048],du[2048],xz[2048],md[8],tu[2048][2048],q[2048],bj[2048],xg[2048],
xb[2048],xj[2048],xJ[2048],xt[2048],xT[2048],xZ[2048],p1,p2,dr,i,tt,rev,gailv;
int si[2048],gg[2048],lo,Y,M,W,YY,MM,WW,cnt,typ,ty,d1,d2,_,cn,slp=167;
int A[]={100,75,75,60,63,55,45,60,40};
int B[]={200,200,200,200,200,200,200,150,200};
int C[]={200,150,130,100,120,130,60,100,110};
int D[]={800,1000,1000,900,1000,1100,1000000000,100000,100000};
bool fr[2048][2048];
struct country{string name,tu;int guoli,bingli,junli,jingji,tudi,zhengzhi,tizhi,zhen;};
struct event{int y,m,w,g,t;};
country guo[2048];
event shj[99999];
int tp[12]={1000,3000,6000,10000,10000,10000,20000,20000,20000,2147483647,2147483647,2147483647};
void ev(int g,int t){shj[++cn]={Y,M,W,g,t};}
void ask(int x,int y){
	if(y<0||y>4)return;
	int z=xT[x];
	if(z<0)z=0;if(z>8)z=z%3+6;
	if(y==1)printf("\n\n\n\n\n\n                     "
	"输入投入的国力（%d国力 → 1兵力）",A[z]);
	if(y==2)printf("\n\n\n\n\n\n                     "
	"输入投入的国力（%d国力 → 1经济力）",B[z]);
	if(y==3)printf("\n\n\n\n\n\n                     "
	"输入投入的国力（%d国力 → 1军事力）",C[z]);
	if(y==4)printf("\n\n\n\n\n\n                     "
	"输入投入的国力（%d国力 → 5政治力）",D[z]);
}
void add(int x,int y,int Z){
	if(y<0||y>4){xg[x]+=Z;return;}
	int z=xT[x];
	if(z<0)z=0;if(z>8)z=z%3+6;
	if(y==1)xb[x]+=Z/A[z],xg[x]+=Z%A[z];
	if(y==2)xJ[x]+=Z/B[z],xg[x]+=Z%B[z];
	if(y==3)xj[x]+=Z/C[z],xg[x]+=Z%C[z];
	if(y==4)xZ[x]+=Z/D[z]*5,xg[x]+=Z%D[z];
}
void sj(int x){
	int t=rand()%100+1;
	if(xT[x]==5||xT[x]==8)
	if(cnt<120&&t%7==0&&Y>=2014)MessageBox(NULL,"富强 民主 文明 和谐\n自由 平等 公正 法治\n爱国 敬业 诚信 友善","社会主义核心价值观",64);
	if(xT[x]>=1&&t>80&&xJ[x]>=200&&q[x]==0){
		xj[x]+=50;q[x]=1;ev(x,-9);if(cnt>=120&&x!=p1&&x!=p2)puts(guo[x].name.c_str());
		if(x==p1&&dr)MessageBox(NULL,"我国生产了火枪！！战斗力大幅提升！！！","我国大事记",64);else
		if(x==p1&&!dr)MessageBox(NULL,"1P生产了火枪！！战斗力大幅提升！！！","1P大事记",64);else
		if(x==p2&&!dr)MessageBox(NULL,"2P生产了火枪！！战斗力大幅提升！！！","2P大事记",64);else
		MessageBox(NULL,"他们生产了火枪！！战斗力大幅提升！！！","敌国大事记",48),cls;
	}
	if(xT[x]>=3&&t>85&&xJ[x]>=700&&q[x]==1){
		xj[x]+=200;q[x]=2;ev(x,-10);if(cnt>=120&&x!=p1&&x!=p2)puts(guo[x].name.c_str());
		if(x==p1&&dr)MessageBox(NULL,"我国生产了坦克！！战斗力大幅提升！！！","我国大事记",64);else
		if(x==p1&&!dr)MessageBox(NULL,"1P生产了坦克！！战斗力大幅提升！！！","1P大事记",64);else
		if(x==p2&&!dr)MessageBox(NULL,"2P生产了坦克！！战斗力大幅提升！！！","2P大事记",64);else
		MessageBox(NULL,"他们生产了坦克！！战斗力大幅提升！！！","敌国大事记",48),cls;
	}
	if(t<4){
		if(xJ[x]>100)xJ[x]-=10;else xJ[x]=xJ[x]*0.9+1e-4+0.5;
		if(x==p1&&dr)MessageBox(NULL,"我国发生了地震！！经济力下降！！！","我国大事记",64);else
		if(x==p1&&!dr)MessageBox(NULL,"1P发生了地震！！经济力下降！！！","1P大事记",64);else
		if(x==p2&&!dr)MessageBox(NULL,"2P发生了地震！！经济力下降！！！","2P大事记",64);else if(cnt<120)
		MessageBox(NULL,"他们发生了地震！！经济力下降！！！","敌国大事记",48);
	}
	if(t>97&&xT[x]<=2||t>90&&xT[x]==6){
		xj[x]-=7;xZ[x]-=10;
		if(x==p1&&dr)MessageBox(NULL,"我国发生了国民暴动！！政治力和军事力下降！！！","我国大事记",64);else
		if(x==p1&&!dr)MessageBox(NULL,"1P发生了国民暴动！！政治力和军事力下降！！！","1P大事记",64);else
		if(x==p2&&!dr)MessageBox(NULL,"2P发生了国民暴动！！政治力和军事力下降！！！","2P大事记",64);else if(cnt<120)
		MessageBox(NULL,"他们发生了国民暴动！！政治力和军事力下降！！！","敌国大事记",48);
	}
	if(t<=30&&gg[x]==0&&xT[x]>=2){
		gg[x]++;xJ[x]+=25<<gg[x];ev(x,-11);if(cnt>=120&&x!=p1&&x!=p2)puts(guo[x].name.c_str());
		if(x==p1&&dr)MessageBox(NULL,"我国发生了第一次工业革命！！生产力大幅提升！！！","我国大事记",64);else
		if(x==p1&&!dr)MessageBox(NULL,"1P发生了第一次工业革命！！生产力大幅提升！！！","1P大事记",64);else
		if(x==p2&&!dr)MessageBox(NULL,"2P发生了第一次工业革命！！生产力大幅提升！！！","2P大事记",64);else
		MessageBox(NULL,"他们发生了第一次工业革命！！生产力大幅提升！！！","敌国大事记",48),cls;
	}
	if(t<=20&&gg[x]==1&&xT[x]>=3){
		gg[x]++;xJ[x]+=25<<gg[x];ev(x,-12);if(cnt>=120&&x!=p1&&x!=p2)puts(guo[x].name.c_str());
		if(x==p1&&dr)MessageBox(NULL,"我国发生了第二次工业革命！！生产力大幅提升！！！","我国大事记",64);else
		if(x==p1&&!dr)MessageBox(NULL,"1P发生了第二次工业革命！！生产力大幅提升！！！","1P大事记",64);else
		if(x==p2&&!dr)MessageBox(NULL,"2P发生了第二次工业革命！！生产力大幅提升！！！","2P大事记",64);else
		MessageBox(NULL,"他们发生了第二次工业革命！！生产力大幅提升！！！","敌国大事记",48),cls;
	}
	if(t<=10&&gg[x]==2&&xT[x]>=6){
		gg[x]++;xJ[x]+=25<<gg[x];ev(x,-13);if(cnt>=120&&x!=p1&&x!=p2)puts(guo[x].name.c_str());
		if(x==p1&&dr)MessageBox(NULL,"我国发生了第三次工业革命！！生产力大幅提升！！！","我国大事记",64);else
		if(x==p1&&!dr)MessageBox(NULL,"1P发生了第三次工业革命！！生产力大幅提升！！！","1P大事记",64);else
		if(x==p2&&!dr)MessageBox(NULL,"2P发生了第三次工业革命！！生产力大幅提升！！！","2P大事记",64);else
		MessageBox(NULL,"他们发生了第三次工业革命！！生产力大幅提升！！！","敌国大事记",48),cls;
	}
	if(t>66){
		if(xT[x]==0&&xZ[x]>=120||xT[x]==1&&xZ[x]>=800){
			string t="政体发生变化！！由"+uu[xT[x]]+"转变为"+uu[xT[x]+1]+"！！！",u="大事记";int v=64;
			if(x==p1&&dr)t="我国"+t,u="我国"+u;else
			if(x==p1&&!dr)t="1P"+t,u="1P"+u;else
			if(x==p2&&!dr)t="2P"+t,u="2P"+u;else
			t="他们"+t,u="敌国"+u,v=48;
			if(v==48&&cnt>=120)puts(guo[x].name.c_str());
			xT[x]++;MessageBox(NULL,t.c_str(),u.c_str(),v);
			if(v==48&&cnt>=120)cls;ev(x,-xT[x]);
		}
		if(xT[x]>=3&&xT[x]<=5&&xZ[x]>=6000){
			string t="政体发生变化！！由"+uu[xT[x]]+"转变为"+uu[xT[x]+3]+"！！！",u="大事记";int v=64;
			if(x==p1&&dr)t="我国"+t,u="我国"+u;else
			if(x==p1&&!dr)t="1P"+t,u="1P"+u;else
			if(x==p2&&!dr)t="2P"+t,u="2P"+u;else
			t="他们"+t,u="敌国"+u,v=48;
			if(v==48&&cnt>=120)puts(guo[x].name.c_str());
			xT[x]+=3;MessageBox(NULL,t.c_str(),u.c_str(),v);
			if(v==48&&cnt>=120)cls;ev(x,-xT[x]);
		}
		if(xT[x]==2&&xZ[x]>=2000){
			string t;
			if(x!=p1&&x!=p2&&cnt>=120)puts(guo[x].name.c_str());
			if(x!=p1&&x!=p2)xT[x]=tt==8||tt==17||tt==18||tt==19||tt==20||tt==21||tt==22||tt==23?rand()%3+3:4,
			t="他们发生了革命，由"+uu[2]+"转变为"+uu[xT[x]]+"！！！",
			MessageBox(NULL,t.c_str(),"敌国大事记",48);
			else{
				string t="政体发生变化！！国家的命运由你抉择\n1帝国主义\n2总统制\n3社会主义",u="大事记";
				if(x==p1&&dr)t="我国"+t,u="我国"+u;else
				if(x==p1&&!dr)t="1P"+t,u="1P"+u;else
				if(x==p2&&!dr)t="2P"+t,u="2P"+u;MessageBox(NULL,t.c_str(),u.c_str(),64);
				xT[x]=MessageBox(NULL,"中止--帝国主义\n重试--总统制\n忽略--社会主义","艰难的抉择",66);
				t="政体发生变化！！由"+uu[2]+"转变为"+uu[xT[x]]+"！！！",u="大事记";
				if(x==p1&&dr)t="我国"+t,u="我国"+u;else
				if(x==p1&&!dr)t="1P"+t,u="1P"+u;else
				if(x==p2&&!dr)t="2P"+t,u="2P"+u;MessageBox(NULL,t.c_str(),u.c_str(),64);
			}
			if(x!=p1&&x!=p2&&cnt>=120)cls;ev(x,-xT[x]);
		}
	}
}
void sj2(int x){
	int u=rand()%100+1;
	if(xb[16]<300&&!si[16])xb[16]=300;
	if(xb[5]<600&&!si[5]&&xt[5]<200)xb[5]=600;
	if(xb[21]<500&&!si[21]&&xt[21]<130)xb[21]=500;
	if(xb[24]<50&&!si[24]&&!sh[46])xb[24]=50;
	if(xb[8]<100&&!si[8])xb[8]=100;
	if(Y>1941&&M>2&&!si[24]&&!sh[46]&&u>60&&u<70){
		sh[46]=1;
		MessageBox(NULL,"日本战事吃紧，资源短缺！！！","世界大事记",64);	
	}
	if(Y>1941&&M>7&&xz[16]==1&&!si[24]&&!sh[47]&&u>60&&u<70){
		sh[47]=1;
		MessageBox(NULL,"日本进行大规模征兵，以抗衡美国！！！","世界大事记",64);	
		xb[24]+=1000;
	}
	if(xt[8]>350&&xz[12]==0&&!si[12]&&!sh[54]){
		sh[54]=1;
		MessageBox(NULL,"西班牙加入轴心国！！！","世界大事记",64);
		xz[12]=2;
	}
	if(xz[5]==1&&!si[3]&&!sh[55]&&u<15){
		sh[55]=1;
		MessageBox(NULL,"冬季战争爆发，芬兰加入轴心国！！！","世界大事记",64);
		xz[3]=2;
	}
	if(Y>=1940&&u>50&&!sh[38]&&!si[24]){
		sh[38]=1;
		MessageBox(NULL,"零式战斗机研发成功！！！","世界大事记",64);
		xj[24]+=300;
	}
	if(si[10]&&xt[8]<100&&Y>=1943&&!sh[52]){
		sh[52]=1;
			MessageBox(NULL,"法国复国,戴高乐成为总统！！！","世界大事记",64);
			bj[10]=10;si[10]=0;int i=10;
			xg[i]=0;xb[i]=500;xj[i]=1500;xJ[i]=300;xt[i]=45;xZ[i]=2005;xT[i]=4;xz[i]=1;
	}
	if(!si[10]&&xt[8]<100&&Y>=1943&&!sh[52]){
		sh[52]=1;
			MessageBox(NULL,"法国复国,戴高乐成为总统！！！","世界大事记",64);
			bj[10]=10;si[10]=0;int i=10;
			xg[i]+=0;xb[i]+=750000/xj[i];xJ[i]=(xJ[i]*xt[i]+13500)/(xt[i]+45);xt[i]+=45;xZ[i]=2005;xT[i]=4;xz[i]=1;
	}
	if(Y>=1941&&M>=10&&!sh[40]&&!si[24]){
		sh[40]=1;
		MessageBox(NULL,"日本进攻东南亚，获得大量土地资源！！！","世界大事记",64);
		xt[24]+=50;
		xJ[24]+=200;
	}
	if(Y>=1940&&u>50&&!sh[39]&&!si[24]&&xt[24]<40){
		sh[39]=1;
		MessageBox(NULL,"军部派出神风敢死队，誓死保卫日本！！！","世界大事记",64);
		xb[24]+=4000;
		for(i=1;i<=28;i++)tu[i][24]+=40000;
	}
	if(u>50&&!sh[51]&&!si[8]&&xt[8]<40){
		sh[51]=1;
		MessageBox(NULL,"柏林战役爆发，德国集结精良部队抵抗！！！","世界大事记",64);
		xb[8]+=3000;
		for(i=1;i<=28;i++)tu[i][8]+=40000;
	}
	if(Y>=1941&&M>8&&u>30&&u<90&&!sh[50]&&!si[8]){
		sh[50]=1;
		MessageBox(NULL,"德国mg-42研制成功！！！","世界大事记",64);
		xj[8]+=300;
	}
	if(u%10==0&&xz[x]==2){
		xb[x]-=50;
		if(x==p1&&dr)MessageBox(NULL,"我国抵抗组织发动袭击，兵力下降！！！","我国大事记",64);else
		if(x==p1&&!dr)MessageBox(NULL,"1P抵抗组织发动袭击，兵力下降！！！","1P大事记",64);else
		if(x==p2&&!dr)MessageBox(NULL,"2P抵抗组织发动袭击，兵力下降！！！","2P大事记",64);else
		MessageBox(NULL,"他们抵抗组织发动袭击，兵力下降！！！","敌国大事记",48);
	}
	if(Y>=1940&&u>50&&!sh[35]&&!si[4]){
		sh[35]=1;
		MessageBox(NULL,"丘吉尔进行演讲，英国大规模动员！！！","世界大事记",64);
		xb[4]+=500;
	}
	if(xt[4]<=30&&!sh[36]&&!si[4]){
		sh[36]=1;
		MessageBox(NULL,"英国进入紧急状态！！！","世界大事记",64);
		xb[4]+=8000;
		xj[4]+=200;
	}
	if(sh[1]&&Y>=1941&&M>6&&u>90&&!si[16]&&!si[8]&&!sh[34]){
		sh[34]=1;
		MessageBox(NULL,"盟军大规模轰炸德国工厂，德国经济严重受损！！！","世界大事记",64);
		xJ[8]-=150;
	}
	if(!sh[31]&&Y==1944&&M==6&&!si[8]&&!si[16]){
		sh[31]=1;
		MessageBox(NULL,"盟军在诺曼底登陆，成功开辟第二战场！！！","世界大事记",64);
		xj[8]-=400;
		tu[16][8]=8000;
		xb[8]-=400;
		if(!si[16]){
			xj[16]-=100;xb[16]-=100;
		}
		if(!si[4]){
			xj[4]-=100;xb[4]-=100;
		}
	}
	if(Y>=1942&&u>50&&u<60&&!sh[45]&&!si[16]&&xb[16]>1000&&xj[16]>500){
		sh[45]=1;
		MessageBox(NULL,"美国援助各地战事！！！","世界大事记",64);
		for(int i=1;i<=28;i++)if(xz[i]==1)xb[i]+=300,xb[16]=(xb[16]*xj[16]-300*xj[i])/xj[16];
	}
	if(Y>=1941&&u>31&&u<40&&!sh[29]&&!si[16]){
		sh[29]=1;
		MessageBox(NULL,"罗斯福进行全国动员！！！","世界大事记",64);
		xb[16]+=2000;
		xj[16]+=100;
	}
	if(!sh[27]&&Y==1942&&M==6&&!si[8]&&!si[5]&&xz[5]==1){
		sh[27]=1;
		MessageBox(NULL,"斯大林格勒战役爆发，德军被击退，国力严重下降！！！","世界大事记",64);
		xj[8]-=600;
		xb[8]-=600;
		xb[5]-=200;
		xj[5]-=200;
	}
	if(Y>=1942&&u>50&&u<60&&!sh[28]&&!si[16]){
		sh[28]=1;
		MessageBox(NULL,"中途岛号航母下水！！！","世界大事记",64);
		xj[16]+=200;
		xb[16]+=400;
	}
	if(Y>=1942&&u<50&&!sh[43]&&!si[8]&&!si[4]){
		sh[43]=1;
		MessageBox(NULL,"俾斯麦号被击沉！！","世界大事记",64);
		xj[8]-=300;
		xb[8]-=500;
	}
	if(xZ[8]<=5960&&u>50&&u<60&&!sh[26]&&!si[8]){
		sh[26]=1;
		MessageBox(NULL,"曼施坦因离世，德国战斗力下降！！！","世界大事记",64);
		xj[8]-=200;
	}
	if(xZ[8]<=5980&&u>50&&u<60&&!sh[13]&&!si[8]){
		sh[13]=1;
		MessageBox(NULL,"隆美尔离世，德国战斗力下降！！！","世界大事记",64);
		xj[8]-=200;
	}
	if(Y>=1941&&M>6&&u<40&&!sh[41]&&!si[5]&&!si[8]&&xz[5]==1){
		sh[41]=1;
		MessageBox(NULL,"希特勒进行对苏宣战演讲！！！","世界大事记",64);
		xb[8]+=1000;
	}
	if(Y>=1940&&u>25&&u<50&&!sh[42]&&!si[8]){
		sh[42]=1;
		MessageBox(NULL,"u型潜艇研发成功，狼群战术出现！！！","世界大事记",64);
		xj[8]+=300;
		xb[8]+=400;
	}
	if(Y>=1941&&u>40&&u<43&&!sh[14]&&si[10]&&!si[8]){
		sh[14]=1;
		MessageBox(NULL,"德国v型导弹研制成功！！！","世界大事记",64);
		xj[8]+=300;
	}
	if(Y>=1942&&u>30&&u<35&&!sh[15]&&!si[8]){
		sh[15]=1;
		MessageBox(NULL,"德国虎式坦克研制成功！！！","世界大事记",64);
		xj[8]+=600;
	}
	if(Y>=1943&&u>23&&u<30&&!sh[16]&&!si[8]){
		sh[16]=1;
		MessageBox(NULL,"德国第一架喷气式飞机试飞成功！！！","世界大事记",64);
		xj[8]+=400;
	}
	if(Y>=1942&&u>23&&u<30&&!sh[17]&&!si[5]){
		sh[17]=1;
		MessageBox(NULL,"苏联t-34投入生产！！！","世界大事记",64);
		xj[5]+=500;
	}
	if(Y>=1943&&M>5&&u>23&&u<40&&!sh[49]&&!si[5]){
		sh[49]=1;
		MessageBox(NULL,"苏联喀秋莎投入生产！！！","世界大事记",64);
		xj[5]+=300;
	}
	if(!sh[18]&&Y>=1940&&u>10&&u<15&&!si[22]&&!si[24]){
		sh[18]=1;
		MessageBox(NULL,"中国共产党发动百团大战，日本损失严重！！！","世界大事记",64);
		xb[24]-=300;
		if(xb[24]<50)xb[24]=50;
		xt[24]-=10;
		xt[22]+=10;
		xb[22]-=50;
	}
	if(Y>=1940&&xt[21]<80&&!sh[24]&&!si[21]){
		sh[24]=1;
		MessageBox(NULL,"中国国民党号召全民族抗战！！！","世界大事记",64);
		xb[21]+=10000;
		xb[22]+=500;
	}
	if(Y>=1940&&u>65&&u<70&&!sh[21]&&!si[16]){
		sh[21]=1;
		MessageBox(NULL,"美国实施罗斯福新政！！！","世界大事记",64);
		xJ[16]+=200;
	}
	if(Y>=1940&&u>90){
		if(xz[11]==0){
			MessageBox(NULL,"匈牙利加入轴心国！！！","世界大事记",64);
			xz[11]=2;
		}else
		if(xz[15]==0){
			MessageBox(NULL,"罗马尼亚加入轴心国！！！","世界大事记",64);
			xz[15]=2;
		}	
	}
	if(!sh[1]&&Y==1941&&M>=1&&u>99&&!si[16]&&xz[16]!=1){
		sh[1]=1;
		MessageBox(NULL,"美国罗斯福下台，法西斯党执政！！","世界大事记",64);
		xb[16]=500;
		if(xz[16]==0)MessageBox(NULL,"美国加入轴心国！！！","世界大事记",64);
		xz[16]=2;
	}
	if(!sh[1]&&Y>=1941&&u>70&&!si[16]&&!si[24]&&xz[16]==0){
		sh[1]=1;
		MessageBox(NULL,"日军偷袭珍珠港，美国损失严重！！！","世界大事记",64);
		xj[24]-=(xb[16]-200)*xj[16]/xj[24];
		xb[16]=0;
		xJ[16]-=200;
		xt[16]-=30;
		if(xz[16]==0)MessageBox(NULL,"美国加入同盟国！！！","世界大事记",64);
		xz[16]=1;
	}
	if(sh[1]&&Y>=1941&&u<50&&!si[16]&&!si[24]&&!sh[33]&&xz[16]==1){
		sh[33]=1;
		MessageBox(NULL,"美国轰炸东京，日本经济严重受损！！！","世界大事记",64);
		xJ[24]-=100;
	}
	if(!sh[56]&&Y>=1942&&u>90&&!si[5]&&!si[24]){
		sh[56]=1;
		MessageBox(NULL,"日军进攻诺门坎，苏联损失严重！！！","世界大事记",64);
		xb[24]-=300*xj[5]/xj[24];
		xb[5]-=300;
		if(xz[5]==0)MessageBox(NULL,"苏联加入同盟国！！！","世界大事记",64);
		xz[5]=1;
	}
	if(!sh[2]&&u>50&&!si[16]&&!si[24]){
		sh[2]=1;
		MessageBox(NULL,"闪电战理论诞生！！！！","世界大事记",64);
		xj[8]+=400;
	}
	if(!sh[3]&&u==100&&!si[24]&&Y>=1941){
		sh[3]=1;
		MessageBox(NULL,"大和号下水，成为世界最大战列舰！！！！","世界大事记",64);
		xj[24]+=400;
		xb[24]+=100;
	}
	if(sh[1]&&!sh[4]&&Y>=1941&&u<30&&M>7&&!si[16]&&!si[24]&&xz[16]==1){
		sh[4]=1;
		MessageBox(NULL,"中途岛海战爆发！！！！","世界大事记",64);
		if(xb[24]*xj[24]<xb[16]*xj[16]){
			MessageBox(NULL,"美国获得胜利！！！！","世界大事记",64);
			tu[16][24]=8000;
		}
		else{	
			MessageBox(NULL,"日本获得胜利！！！！","世界大事记",64);
			tu[24][16]=8000;
		}
		xb[16]-=500;
		xb[24]-=500;
	}
	if(sh[1]&&sh[4]&&!sh[11]&&Y>=1942&&u>50&&!si[16]&&!si[24]&&xz[16]==1){
		sh[11]=1;
		MessageBox(NULL,"硫磺岛海战爆发！！！！","世界大事记",64);
		if(xb[24]*xj[24]<xb[16]*xj[16]){
			MessageBox(NULL,"美国获得胜利！！！！","世界大事记",64);
			tu[16][24]=8000;
		}
		else{	
			MessageBox(NULL,"日本获得胜利！！！！","世界大事记",64);
			tu[24][16]=8000;
		}
		xb[16]-=500;
		xb[24]-=500;
	}
	if(sh[1]&&sh[4]&&sh[11]&&!sh[12]&&Y>=1943&&u>50&&!si[16]&&!si[24]&&xz[16]==1){
		sh[12]=1;
		MessageBox(NULL,"菲律宾海战爆发！！！！","世界大事记",64);
		if(xb[24]*xj[24]<xb[16]*xj[16]){
			MessageBox(NULL,"美国获得胜利！！！！","世界大事记",64);
			tu[16][24]=800;
		}
		else{	
			MessageBox(NULL,"日本获得胜利！！！！","世界大事记",64);
			tu[24][16]=800;
		}
		xb[16]-=500;
		xb[24]-=500;
	}
	if(!sh[57]&&Y>=1943&&M>3&&u>70){
		sh[57]=1;
		MessageBox(NULL,"大西洋海战爆发！！！！","世界大事记",64);
		int zzhan1=0,zzhan2=0;
		if(!si[8])zzhan1+=xb[8]*xj[8],xb[8]-=500;
		if(!si[13])zzhan1+=xb[13]*xj[13],xb[13]-=500;
		if(!si[10])zzhan2+=xb[10]*xj[10],xb[10]-=500;
		if(!si[16]&&xz[16]==1)zzhan2+=xb[16]*xj[16],xb[16]-=500;
		if(!si[16]&&xz[16]==2)zzhan1+=xb[16]*xj[16],xb[16]-=500;
		if(zzhan1==0||zzhan2==0){
			MessageBox(NULL,"该大西洋海战无意义！！！","世界大事记",64);
		}
		if(zzhan1>zzhan2){
			MessageBox(NULL,"轴心国获得胜利！！！！","世界大事记",64);
			tu[8][16]=9000;
		}
		else{	
			MessageBox(NULL,"同盟国获得胜利！！！！","世界大事记",64);
			tu[16][8]=9000;
		}
	}
	if(!sh[5]&&Y>=1941&&M>3&&u>70){
		sh[5]=1;
		MessageBox(NULL,"大西洋海战爆发！！！！","世界大事记",64);
		int zzhan1=0,zzhan2=0;
		if(!si[8])zzhan1+=xb[8]*xj[8],xb[8]-=500;
		if(!si[13])zzhan1+=xb[13]*xj[13],xb[13]-=500;
		if(!si[10])zzhan2+=xb[10]*xj[10],xb[10]-=500;
		if(!si[16]&&xz[16]==1)zzhan2+=xb[16]*xj[16],xb[16]-=500;
		if(!si[16]&&xz[16]==2)zzhan1+=xb[16]*xj[16],xb[16]-=500;
		if(zzhan1>zzhan2){
			MessageBox(NULL,"轴心国获得胜利！！！！","世界大事记",64);
			tu[8][16]=9000;
		}
		else{	
			MessageBox(NULL,"同盟国获得胜利！！！！","世界大事记",64);
			tu[16][8]=9000;
		}
	}
	if(!sh[6]&&Y>=1940&&u<30&&M>3&&!si[8]&&!si[4]){
		sh[6]=1;
		MessageBox(NULL,"不列颠空战爆发！！！！","世界大事记",64);
		xb[8]-=500;
		xb[4]-=500;
		if(xb[8]*xj[8]/3*1<xb[4]*xj[4]){
			MessageBox(NULL,"英国获得胜利！！！！","世界大事记",64);
			tu[4][8]=2000;
		}
		else{	
			MessageBox(NULL,"德国获得胜利！！！！","世界大事记",64);
			tu[8][4]=2000;
		}
	}
	if(Y>=1942&&M>2&&!sh[25]&&u>80&&!si[5]){
		sh[25]=1;
		MessageBox(NULL,"苏联迎来几百年一遇的寒流！！！！","世界大事记",64);
		for(int i=1;i<=28;i++)tu[i][5]+=40000;
	}
	if(!sh[20]&&Y==1941&&M==6&&!si[8]&&!si[5]){
		sh[20]=1;
		MessageBox(NULL,"德国大举进攻苏联，苏德战争爆发！！","世界大事记",64);
		if(xz[5]==0)MessageBox(NULL,"苏联加入同盟国！！！","世界大事记",64);
		xb[8]-=xb[5]*xj[5]/xj[8]; 
		xb[5]=0;
		xz[5]=1;
	}
	if(!sh[19]&&Y>=1941&&!si[8]&&!si[5]&&xt[5]<200){
		sh[19]=1;
		MessageBox(NULL,"苏联卫国战争爆发，斯大林号令全国群众一起对抗法西斯！！","世界大事记",64);
		xb[5]+=10000;
		xj[5]+=200;
	}
	if(!sh[7]&&Y>=1943&&(u>97||(u>85&&sh[9]))&&!si[16]){
		sh[7]=1;
		MessageBox(NULL,"美国研制原子弹成功,军事力大大增强！！","世界大事记",64);
		xj[16]+=400;
	}
	if(u==1&&(!sh[10]&&!sh[9])){
		sh[10]=1;
		MessageBox(NULL,"爱因斯坦决定留在德国！！","世界大事记",64);
	}
	if(u>90&&(!sh[10]&&!sh[9])){
		sh[9]=1;
		MessageBox(NULL,"爱因斯坦进入美国！！","世界大事记",64);
	}
}
void sj1(int x){
	if(rand()%100<66)return;
	if(x==1&&!sh[1]&&xZ[1]>=70&&Y>=-365){
		sh[1]=1;
		MessageBox(NULL,"秦国进行商鞅变法！！！","世界大事记",64);
		xZ[1]+=80;
	}
	if(!sh[2]&&xt[11]<25){
		sh[2]=1;
		MessageBox(NULL,"越王卧薪尝胆，苦练军队！！！","世界大事记",64);
		xj[11]*=2;
	}
}
int up(int t){
	if(xb[t]<0)xb[t]=0;
	int r=xJ[t]*xt[t]/10-xj[t]*xb[t]/100;
	int z=xT[t];if(z<0)z=0;if(z>8)z=z%3+6;
	if(r>tp[z])r=tp[z];if(r<_)r=_;return r;
}
int vs(int x,int y,int z){
	int z1=z*xj[x]-tu[x][y]*10,z2=xb[y]*xj[y];
	if(z1<=z2){
		if(z1>0)xb[y]-=z1/xj[y];xb[x]-=z;xb[x]+=!!z;return 0;
	}
	xb[x]-=(z2+tu[x][y]*10)/xj[x];xb[y]=!!xb[y];return z-(z2+tu[x][y]*10)/xj[x];
}
int calc(int y,int z=1){
	int t=0,D=1e9;
	for(int j=rev?cnt:1;rev?j:j<=cnt;rev?j--:j++)if(!si[j]&&j!=y&&!fr[y][j])
	if(tu[y][j]<D)D=tu[y][j],t=j;
	if(z&&xj[y])printf("%s(%d) ",guo[t].name.c_str(),(xb[t]*xj[t]+tu[y][t]*10)/xj[y]+1);
	for(int j=rev?cnt:1;rev?j:j<=cnt;rev?j--:j++)if(!si[j]&&j!=y&&!fr[y][j])
	if(tu[y][j]<=d1){if(z&&xj[y])printf("%s(%d)\n",guo[j].name.c_str(),(xb[j]*xj[j]+tu[y][j]*10)/xj[y]+1);return t;}
	if(z)putchar(10);return t;
} 
bool cmp(int x,int y,int z){
	if(x>Y)return 0;
	if(x<Y)return 1;
	if(y<M)return 1;
	if(y>M)return 0;
	return z*7-6<=W;
}
void sj3(int x){
	int u=rand()%100+1;
	if(xb[1]<66)xb[1]=66;
	if(xb[19]<66)xb[19]=66;
	if(!sh[1]&&!si[18]&&!si[1]&&cmp(2016,1,2)&&u>96){
		sh[1]=1;xz[18]=2;xb[18]+=88,xj[18]+=88;
		MessageBox(NULL,"鲍东方使用赵乐毅洛谷账号在1101提交\n"
"“\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
钛手钛手钛手钛手钛手钛手钛手钛手钛手钛手\n\
                                      ”\n"
		"！！！","世界大事记",64);	
	}
	if(!sh[2]&&!si[1]&&!si[15]&&!si[19]&&cmp(2016,1,3)&&u<5){
		sh[2]=1;MessageBox(0,"鲍东方修改詹致豪POJ的刷题量为3055题！！！","世界大事记",64);
		xb[1]-=50,xj[1]-=50,xJ[1]-=50;
	}
	if(!sh[3]&&!si[1]&&!si[19]&&cmp(2016,2,3)&&u>96){
		sh[3]=1;MessageBox(0,"鲍东方在模拟赛时泄题！！！","世界大事记",64);
		for(int i=2;i<=19;i++)xb[i]+=50,xj[i]+=50,xJ[i]+=50;
	}
	if(!sh[4]&&!si[9]&&!si[17]&&cmp(2016,3,1)&&u<90){
		sh[4]=1;MessageBox(0,"张逸凡在模拟赛得了最后一名，沈序戎吃屎！！！","世界大事记",64);
	}
	if(!sh[5]&&!si[1]&&!si[19]&&cmp(2016,3,1)&&sh[4]&&u>92){
		sh[5]=1;MessageBox(0,"鲍东方总是打游戏，被关进隔壁！！！","世界大事记",64);
		for(int i=2;i<=19;i++)tu[1][i]+=2333;xj[1]+=100;
	}
	if(!sh[6]&&sh[5]&&!si[12]&&!si[18]&&cmp(2016,3,3)&&u>50&&xz[18]==2){
		sh[6]=1;MessageBox(0,"赵乐毅选择和王天乐住一间房！！！","世界大事记",64);
	}
	if(!sh[7]&&sh[6]&&!si[1]&&u<50){
		sh[7]=1;MessageBox(0,"鲍东方在群上发 赵乐毅 和 王天乐 爱上了！！！","世界大事记",64);
		xb[18]+=50,xj[18]+=50;xz[12]=2;xb[12]+=100,xj[12]+=100;
	}
	if(!sh[8]&&sh[7]&&!si[1]&&u<20&&cmp(2016,3,4)){
		sh[8]=1;xj[1]+=54;
		MessageBox(0,"鲍东方在ZJOI2016Day1得分54分！！！","世界大事记",64);
	}
	if(!sh[9]&&sh[5]&&sh[8]&&!si[19]&&!si[1]&&u>95){
		sh[9]=1;MessageBox(0,"鲍东方表现进步，回到原先地方！！！","世界大事记",64);
		for(int i=2;i<=19;i++)tu[1][i]-=2333;xj[1]-=100;
	}
	if(!sh[10]&&!si[1]&&!si[17]&&cmp(2016,4,2)&&u>93){
		sh[10]=1;MessageBox(0,"鲍东方盗取张逸凡元素周期表大图！！！","世界大事记",64);
		xz[17]=2;xj[17]+=100,xb[17]+=100;
	}
	if(!sh[11]&&sh[9]&&!si[1]&&!si[19]&&cmp(2016,4,3)&&u<5){
		sh[11]=1;MessageBox(0,"鲍东方又被关进隔壁！！！","世界大事记",64);
		for(int i=2;i<=19;i++)tu[1][i]+=3000;xj[1]+=125;
	}
	if(!sh[15]&&xz[12]==2&&!si[1]&&!si[12]&&sh[11]&&u>92){
		sh[15]=1;MessageBox(0,"鲍东方和王天乐关系改善！！！","世界大事记",64);
		xz[12]=0;
	} 
	if(!sh[12]&&sh[11]&&!si[1]&&u<20&&cmp(2016,4,4)){
		sh[12]=1;xj[1]+=40;
		MessageBox(0,"鲍东方在ZJOI2016Day2得分40分！！！","世界大事记",64);
	}
	if(!sh[13]&&sh[12]&&!si[1]&&!si[19]&&cmp(2016,4,4)&&u>95){
		sh[13]=1;xb[1]+=66;
		MessageBox(0,"鲍东方被停课一周！！！","世界大事记",64);
		for(int i=2;i<=18;i++)tu[1][i]+=100000,tu[i][1]+=100000;
		tu[1][19]+=100000;
	}
	if(!sh[14]&&sh[13]&&!si[1]&&!si[19]&&cmp(2016,5,1)){
		sh[14]=1;xj[19]-=200;xb[19]-=200;
		MessageBox(0,"鲍东方诅咒董烨华死了，董烨华军事力兵力下降！！！","世界大事记",64);
	}
	if(!sh[16]&&sh[13]&&!si[1]&&!si[19]&&cmp(2016,5,2)){
		sh[16]=1;
		MessageBox(0,"鲍东方停课结束！！！","世界大事记",64);
		for(int i=2;i<=18;i++)tu[1][i]-=100000,tu[i][1]-=100000;
		tu[1][19]-=100000;
	}
	if(!sh[17]&&!si[1]&&!si[19]&&cmp(2016,6,1)&&x!=1&&u<8){
		sh[17]=1;xb[1]-=100;xj[1]-=100;if(xb[1]<0)xb[1]=0;
		MessageBox(0,"董烨华向鲍东方家长告状！！！","世界大事记",64);
	}
	if(!sh[18]&&sh[17]&&!si[1]&&!si[19]&&cmp(2016,6,3)&&x!=1&&u>93){
		sh[18]=1;xb[1]-=100;xj[1]-=100;if(xb[1]<0)xb[1]=0;
		MessageBox(0,"董烨华向鲍东方家长再次告状！！！","世界大事记",64);
	}
	if(!sh[19]&&sh[18]&&!si[1]&&!si[19]&&cmp(2016,7,1)&&x!=1&&u<7){
		sh[19]=1;xb[1]-=100;xj[1]-=100;if(xb[1]<0)xb[1]=0;
		MessageBox(0,"董烨华向鲍东方家长再次告状！！！","世界大事记",64);
	}
	if(!sh[20]&&sh[19]&&!si[1]&&cmp(2016,7,3)||!sh[20]&&!si[1]&&cmp(2016,7,4)){
		sh[20]=1;MessageBox(0,"鲍东方向陈合力告状，引起全部同学公愤！！！","世界大事记",64);
		for(int i=2;i<=18;i++)if(xz[i]!=1)xz[i]=2,xb[i]+=50,xj[i]+=50,tu[i][1]+=1234;
		if(xz[12]==2)xz[12]=0;tu[19][1]=tu[1][19]=1000000;
	}
	if(!sh[21]&&sh[20]&&cmp(2016,8,1)&&x!=1){
		sh[21]=1;MessageBox(0,"全部人上文化课！！！","世界大事记",64);
		for(int i=2;i<=18;i++)if(xz[i]==2&&i!=17)xz[i]=0;
		for(int i=1;i<=19;i++)for(int j=1;j<=19;j++)
		if(i==j)tu[i][j]=0;else if(i==19||j==19)tu[i][j]=10000;else tu[i][j]=1000;
	}
	if(!sh[22]&&cmp(2016,8,3)&&u<8&&!si[1]&&!si[17]&&xz[17]==2){
		sh[22]=1;MessageBox(0,"张逸凡把鲍东方移出ZYF粉丝团群！！！","世界大事记",64);
		xj[1]-=150;xb[1]-=150;if(xb[1]<0)xb[1]=0;
		for(int i=2;i<=18;i++)tu[1][i]+=3000;
	}
	if(!sh[23]&&cmp(2016,8,4)&&u>92&&sh[22]&&!si[1]&&!si[17]){
		sh[23]=1;MessageBox(0,"鲍东方诅咒张逸凡死了，张逸凡军事力兵力下降！！！","世界大事记",64);
		xb[17]-=100;xj[17]-=100;if(xb[17]<0)xb[17]=0;
	}
	static int T[]={0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0};
	if(!sh[24]&&sh[21]&&!si[17]&&cmp(2016,9,1)&&u<7){
		sh[24]=1;MessageBox(0,"张逸凡化学96分第一名！！！","世界大事记",64);
		xb[17]+=66;
	}
	if(!sh[25]&&cmp(2016,9,2)&&u>95&&!si[19]){
		sh[25]=1;MessageBox(0,"很多人去机房！！！","世界大事记",64);
		for(int i=1;i<=18;i++)for(int j=1;j<=18;j++)if(i==j)tu[i][j]=0;
		else if(T[i]^T[j])tu[i][j]=5000;else tu[i][j]=1000;
		for(int i=2;i<=18;i++)tu[1][i]+=sh[22]?4000:1000;
		for(int i=2;i<=18;i++)tu[i][19]=tu[19][i]=5000-4000*T[i];tu[1][i]=14000+3000*sh[22];
		tu[i][1]=14000;
	}
	if(!sh[26]&&sh[25]&&cmp(2016,10,3)&&u<6&&!si[19]){
		sh[26]=1;MessageBox(0,"全部人去机房，NOIP前集训正式开始！！！","世界大事记",64);
		for(int i=1;i<=18;i++)for(int j=1;j<=18;j++)if(i==j)tu[i][j]=0;
		else tu[i][j]=1000;
		for(int i=2;i<=18;i++)tu[1][i]+=sh[22]?4000:1000;
		for(int i=2;i<=18;i++)tu[i][19]=tu[19][i]=1000;tu[1][i]=10000+3000*sh[22];
		tu[i][1]=10000;
	}
	if(!sh[27]&&sh[26]&&cmp(2016,11,1)&&u>92&&!si[1]&&!si[19]){
		sh[27]=1;MessageBox(0,"鲍东方模拟赛次次很差，董烨华失去信心！！！","世界大事记",64);
		xb[1]-=66;xj[1]-=66;
	}
	if(!sh[28]&&sh[27]&&u<8&&!si[1]&&!si[19]){
		sh[28]=1;MessageBox(0,"进入完全联赛状态！！！","世界大事记",64);
		for(int i=1;i<=19;i++)for(int j=1;j<=19;j++)tu[i][j]=1e8;
	}
	if(!sh[29]&&sh[28]&&!si[1]&&!si[19]&&cmp(2016,11,3)){
		sh[29]=1;MessageBox(0,"鲍东方当面说第一件事把董烨华杀死！！！","世界大事记",64);
		xj[19]-=150;
	} 
	if(!sh[30]&&sh[29]&&cmp(2016,11,4)){
		sh[30]=1;MessageBox(0,"联赛完毕，全部同学文化课！！！","世界大事记",64);
		for(int i=1;i<=18;i++)for(int j=1;j<=18;j++)if(i==j)tu[i][j]=0;
		else tu[i][j]=1000;
		for(int i=2;i<=18;i++)tu[1][i]+=sh[22]?4000:1000;
		for(int i=2;i<=18;i++)tu[i][19]=tu[19][i]=1000;tu[1][19]=20000+3000*sh[22];
		tu[19][1]=10000;
	}
	static int F[]={0,1,0,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,0,0};
	int&x1=sh[51],&x2=sh[52],&x3=sh[53],&x4=sh[54],&NOI=sh[50],&x0=sh[49];
	if(!sh[31]&&sh[30]&&!si[1]&&!si[19]&&cmp(2016,11,4)){
		sh[31]=1;char ch[233];sprintf(ch,"鲍东方联赛得了%d分，董烨华损失严重！！！",x0=xt[19]);
		MessageBox(0,ch,"世界大事记",64);
		xb[19]-=xt[19];if(xb[19]<0)xb[19]=0;
		xj[19]-=xt[19];xb[1]+=1000+xt[19];xj[1]+=xt[19];xT[19]=3;
	}
	if(!sh[32]&&sh[31]&&!si[1]&&!si[19]&&cmp(2016,12,1)){
		sh[32]=1;MessageBox(0,"董烨华不允许鲍东方参加省选集训但允许其他分数更低的参加！！！","世界大事记",64);
		xb[1]+=233;xj[1]+=233;F[1]=0;
	}
	if(!sh[33]&&sh[32]&&!si[1]&&!si[19]&&cmp(2016,12,2)&&u<7){
		sh[33]=1;xj[19]-=233;xb[19]-=233;if(xj[19]<0)xj[19]=0;
		MessageBox(0,"鲍东方诅咒董烨华死后再死，董烨华军事力兵力下降！！！","世界大事记",64);
	}
	if(!sh[34]&&sh[30]&&!si[1]&&u>91&&cmp(2016,12,2)){
		sh[34]=1;MessageBox(0,"鲍东方化学93分第一名！！！","世界大事记",64);
		xj[1]+=100;
	}
	if(!sh[35]&&sh[33]&&!si[1]&&!si[19]&&cmp(2016,12,3)&&u>45&&u<55){
		sh[35]=1;MessageBox(0,"省选集训正式开始！！！","世界大事记",64);
		for(int i=1;i<=18;i++)for(int j=1;j<=18;j++)if(i==j)tu[i][j]=0;
		else if(F[i]^F[j])tu[i][j]=5000;else tu[i][j]=1000;
		for(int i=2;i<=18;i++)tu[1][i]+=sh[22]?4000:1000;
		for(int i=2;i<=18;i++)tu[i][19]=tu[19][i]=5000-4000*F[i];tu[1][19]=14000+3000*sh[22];
		tu[19][1]=14000;
	}
	if(!sh[36]&&sh[35]&&!si[1]&&!si[12]&&cmp(2016,12,4)&&u<8){
		sh[36]=1;MessageBox(0,"王天乐给鲍东方发送资料，正式加入反董烨华集团！！！","世界大事记",64);
		xz[12]=1;tu[19][12]=tu[19][1]+1000;xb[12]+=454;xj[12]+=454;xT[12]=3;
	}
	if(!sh[37]&&sh[34]&&!si[1]&&u>92&&cmp(2016,12,4)){
		sh[37]=1;MessageBox(0,"鲍东方数学AK了！！！","世界大事记",64);
		xj[1]+=150;
	}
	if(!sh[38]&&sh[36]&&!si[1]&&!si[19]&&cmp(2017,1,1)){
		sh[38]=1;MessageBox(0,"鲍东方在家准备省选！！！","世界大事记",64);xT[1]+=3;
		for(int i=2;i<=18;i++)tu[1][i]+=100000,tu[i][1]+=100000;
	}
	if(!sh[39]&&sh[38]&&!si[1]&&!si[19]&&u<8){
		sh[39]=1;MessageBox(0,"董烨华不允许鲍东方参加冬令营！！！","世界大事记",64);
		//xb[1]+=233;xj[1]+=233;
	}
	if(!sh[40]&&sh[39]&&!si[1]&&!si[19]&&cmp(2017,2,1)&&u>93){
		sh[40]=1;/*xj[19]-=233;xb[19]-=233;*/if(xj[19]<0)xj[19]=0;
		MessageBox(0,"鲍东方诅咒董烨华死后再死，董烨华军事力兵力下降！！！","世界大事记",64);
	}
	if(!sh[41]&&sh[38]&&!si[1]&&cmp(2017,2,2)&&u<8){
		sh[41]=1;xj[1]+=66;
		MessageBox(0,"鲍东方在BZOJ过了[ZJOI2016]大森林！！！","世界大事记",64);
	}
	if(!sh[42]&&sh[40]&&!si[1]&&!si[19]&&cmp(2017,3,2)&&u<8){
		sh[42]=1;MessageBox(0,"董烨华允许鲍东方回到学校参加最后3场模拟赛！！！","世界大事记",64);
		for(int i=2;i<=18;i++)tu[1][i]-=100000,tu[i][1]-=100000;xz[12]=0;
	}
	if(!sh[43]&&sh[42]&&!si[1]&&!si[19]&&cmp(2017,3,3)&&u<8){
		sh[43]=1;x2=rand()%200+100;x1=rand()%(x2+1);
		char ch[233];sprintf(ch,"鲍东方在ZJOI2017Day1得分%d分，最高分%d分！！！",x1,x2);
		MessageBox(0,ch,"世界大事记",64);
		xb[1]+=300./x2*x1;xj[1]+=300./x2*x1;
	}
	if(!sh[44]&&sh[43]&&!si[1]&&!si[19]&&cmp(2017,4,3)&&u<8){
		sh[44]=1;x4=rand()%200+100;x3=rand()%(x4+1);
		char ch[233];sprintf(ch,"鲍东方在ZJOI2017Day2得分%d分，最高分%d分！！！",x3,x4);
		MessageBox(0,ch,"世界大事记",64);
		xb[1]+=300./x4*x3;xj[1]+=300./x4*x3;
	}
	if(!sh[45]&&sh[44]&&!si[1]&&!si[19]&&cmp(2017,4,3)&&u>90){
		double T=1.*sh[49]/600*0.3+1./x2*x1*0.3+1./x4*x3*0.4;sh[45]=1;
		char ch[233];sprintf(ch,"鲍东方总共%lf分！！！",T);
		MessageBox(0,ch,"世界大事记",64);
		if(T>1)MessageBox(0,"鲍东方使用作弊手段获得分数，被取消参赛资格！！！！！！","世界大事记",64),NOI=-4;else 
		if(T>=0.6)MessageBox(0,"鲍东方进了省队！！！！！！！！！！！！董烨华损失极其严重！！！！！！！！！！！！","世界大事记",64),NOI=1;
		else MessageBox(0,"鲍东方没有进省队！！！","世界大事记",64),NOI=-1;
	}
	if(NOI==1){
		double T=1.*sh[49]/600*0.3+1./x2*x1*0.3+1./x4*x3*0.4;
		for(int i=2;i<=19;i++)tu[1][i]=0,tu[12][i]=1000;
		xb[19]-=T*1000;xj[19]-=T*1000;
		if(xb[19]<0)xb[19]=0;
		if(xj[19]<0)xj[19]=0;NOI=2;
	}
	if(NOI==-4){
		xb[1]-=xb[1]/3,xj[1]-=xj[1]/3;xT[1]=2;NOI=-3;
	}
	if(NOI==-1&&cmp(2017,6,1)&&u%10==0){
		int t=rand();
		if(t<2048)MessageBox(0,"鲍东方获得奖励名额！！！","世界大事记",64),NOI=3;
		else if(t<24576)MessageBox(0,"鲍东方获得付费D类名额！！！","世界大事记",64),xj[1]-=4400,NOI=4;
		else MessageBox(0,"鲍东方没有获得奖励名额！！！","世界大事记",64)
		,NOI=-2,xT[19]=6,xT[1]=3;
	}
	if(!sh[46]&&cmp(2017,7,3)&&NOI>0){
		int t=rand();if(sh[22])t=min(t,rand());sh[46]=1;if(NOI==4&&t<4096)t=5000;
		if(t<4096)MessageBox(0,"鲍东方进入国家集训队，董烨华受到有史以来最大的重创！！！","世界大事记",64);
		if(t<4096)tu[1][19]=0,xg[19]=0,xb[19]=0,xJ[19]=0,xj[19]=0,xT[19]=-1; 
		if(t>=4096&&t<8192)MessageBox(0,"鲍东方和北大签一本，董烨华受到重创！！！","世界大事记",64);
		if(t>=4096&&t<8192){
		double T=1.*sh[49]/600*0.3+1./x2*x1*0.3+1./x4*x3*0.4;
		for(int i=2;i<=19;i++)tu[1][i]=0,tu[12][i]=1000;xb[19]-=T*1000;xj[19]-=T*1000;
		if(xb[19]<0)xb[19]=0;if(xj[19]<0)xj[19]=0;
		}
		if(t>=8192&&t<28672)MessageBox(0,"鲍东方和其他学校签一本！！！","世界大事记",64);
		if(t>=28672)MessageBox(0,"鲍东方没有和任何学校签一本！！！","世界大事记",64),
		xT[19]=6,xT[1]=si[19]?6:3,NOI=-3,xb[1]-=xb[1]/3,xj[1]-=xj[1]/3;
	}
	//NiroBC
	if(!sh[47]&&dr&&(p1==1&&si[19]||p1==19&&si[1])&&NOI>0){
		sh[47]=1;++cnt;
		guo[20].zhen=3-guo[p1].zhen;guo[20].name="NiroBC";guo[20].guoli=0;guo[20].tudi=200;guo[20].jingji=11000;guo[20].bingli=7000;guo[20].junli=2000;guo[20].zhengzhi=0;guo[20].tizhi=6;
		for(i=cnt;i<=cnt;i++){
		xg[i]=guo[i].guoli;
		xb[i]=guo[i].bingli;
		xj[i]=guo[i].junli;
		xJ[i]=guo[i].jingji;
		xt[i]=guo[i].tudi;
		xZ[i]=guo[i].zhengzhi;
		xT[i]=guo[i].tizhi;
		xz[i]=guo[i].zhen;
		du[i]=0;bj[i]=i;gg[i]=3;si[i]=0;
		guo[i].tu="国土";
		}tu[1][20]=tu[20][1]=tu[19][20]=tu[20][19]=5000;
		for(int i=2;i<=18;i++)tu[i][20]=tu[20][i]=1e8;
		xg[p1]+=xb[p1]*A[xT[p1]];xb[p1]=0;int t=xg[p1];xg[p1]=0;add(p1,3,t);
	}
	if(!sh[48]&&NOI>2){
		sh[48]=1;MessageBox(0,"鲍东方继续在家准备NOI！！！","世界大事记",64);
		for(int i=2;i<=18;i++)tu[1][i]+=100000,tu[i][1]+=100000;
	}
}
void sj4(int x){
	int t=rand();//t%=1024;if(t>=512)t+=31000;
	//if(x==8||x==884){cls;printf("x=%d t=\n",x);scanf("%d",&t);}
	if(t<320&&x==884&&!sh[884]&&!si[884]){
		int v[1000],w=0,u;
		for(int i=1;i<=cnt;i++)if(i!=8&&!si[i]&&guo[i].guoli==160&&!(sh[i]&4))v[++w]=i;
		u=v[rand()%w+1];if(t<64&&!(sh[8]&4))u=8;
		char ch[233];
		if(sh[u]&1)sprintf(ch,"杨佩琼处分%s，对其采取严重警告处分！！！",guo[u].name.c_str()),sh[u]|=4;
		else sprintf(ch,"杨佩琼处分%s，对其采取行政警告处分！！！",guo[u].name.c_str()),sh[u]|=1;
		MessageBox(0,ch,"世界大事记",64);fr[884][u]=fr[u][884]=0;
		xj[u]-=xj[u]/4,xb[u]-=xb[u]/4;
	}
	if((sh[x]&1)&&!(sh[x]&2)&&t>30000&&x!=884){
		sh[x]|=2;xj[884]=xj[884]*6/7;xb[884]=xb[884]*6/7;char ch[233];
		sprintf(ch,"%s诅咒杨佩琼死了，杨佩琼军事力兵力下降！！！",guo[x].name.c_str());
		MessageBox(0,ch,"世界大事记",64);
	}
	if((sh[x]&4)&&!(sh[x]&8)&&t>30000&&x!=884){
		sh[x]|=8;xj[884]=xj[884]*4/5;xb[884]=xb[884]*4/5;char ch[233];
		sprintf(ch,"%s诅咒杨佩琼死后再死，杨佩琼军事力兵力下降！！！",guo[x].name.c_str());
		MessageBox(0,ch,"世界大事记",64);
	}
	if(x==8&&t<128&&(sh[8]&1)&&!(sh[8]&4)&&tp[xT[8]]>=tp[xT[884]]){
		MessageBox(0,"鲍东方宣布杨佩琼对其行政警告处分为非法！！！","世界大事记",64);
		sh[8]&=-4;
	}
	if(x==884&&t<128&&(sh[884]&1)&&tp[xT[884]]>=tp[xT[8]]){
		MessageBox(0,"杨佩琼宣布鲍东方对其行政警告处分为非法！！！","世界大事记",64);
		sh[884]&=-4;
	}
	if(x==8&&t>=128&&t<384&&(sh[8]&4)){
		MessageBox(0,"鲍东方宣布杨佩琼对其严重警告处分为非法！！！","世界大事记",64);
		sh[8]&=-13;
	}
	if(x==8&&t>=384&&t<=512&&!sh[884]&&!fr[8][884]&&tp[xT[8]]>tp[xT[884]]&&!sh[8]){
		MessageBox(0,"鲍东方对杨佩琼行政警告！！！","世界大事记",64);
		sh[884]=1;xj[884]-=xj[884]/4,xb[884]-=xb[884]/4;
	}
	if((sh[x]&1)&&!(sh[x]&2)&&t>30000&&x==884){
		sh[x]|=2;xj[8]=xj[8]*5/6;xb[8]=xb[8]*5/6;
		MessageBox(0,"杨佩琼诅咒鲍东方死了，鲍东方军事力兵力下降！！！","世界大事记",64);
	}
}
bool jc(int x){
	if(xb[x]<0)xb[x]=0;if(x==p1||x==p2){cls;
		printf("               公元   %d 年      %d月 %d日  \n\n\n\n          %s",Y,M,W,guo[x].name.c_str());
		printf("\n\n\n        %c%c国力： %d      兵力： %d      军队战斗力： %d"
		"      经济力： %d      %s： %d       政体： %d\n\n"
		"                        1、战争\n                        2、发展\n"
		"                        3、下一回合\n                        4、存档\n"
		"                        5、事件查看\n                        6、体制分布\n"
		"                        7、速度调整",(dr?' ':x==p1?'1':'2'),(dr?' ':':'),
		xg[x],xb[x],xj[x],xJ[x],guo[x].tu.c_str(),xt[x],xZ[x]);
		int t;scanf("%d",&t);
		#define print(...) fprintf(__,__VA_ARGS__)
		if(t==4){
		FILE*__=fopen("a","w");
		print("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n"
		,tt,cnt,typ,ty,d1,d2,_,Y,M,W,YY,MM,WW,p1,p2,dr,gailv);
		print("%s %s %s\n",orz.c_str(),z1.c_str(),z2.c_str());
		for(int i=1;i<=1200;i++)print("%d ",sh[i]);print("\n");
		for(int i=1;i<=cnt;i++)print("%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		du[i],xz[i],q[i],bj[i],xg[i],xb[i],xj[i],xJ[i],xt[i],xT[i],xZ[i],si[i],gg[i]);
		for(int i=1;i<=cnt;i++,print("\n"))for(int j=1;j<=cnt;j++)print("%d ",tu[i][j]*(fr[i][j]?-1:1));
		for(int i=1;i<=cnt;i++)print("%s %d %d %d %d %d %d %d %d %s\n",
		guo[i].name.c_str(),guo[i].guoli,guo[i].bingli,guo[i].junli,guo[i].jingji,
		guo[i].tudi,guo[i].zhengzhi,guo[i].tizhi,guo[i].zhen,guo[i].tu.c_str());
		print("%d %d %d\n",x==p1?1:2,rev,cn);
		for(int i=1;i<=cn;i++)print("%d %d %d %d %d\n",shj[i].y,shj[i].m,shj[i].w,shj[i].g,shj[i].t);
		fclose(__);
		}
		if(t==5){
			cls;printf("\n                      事件总数：%d\n\n",cn);
			for(int i=1;i<=cn;i++){
				printf("%12d、%4d 年%3d 月%3d 日，",i,shj[i].y,shj[i].m,shj[i].w);
				if(shj[i].g){
					int t=shj[i].t;
					for(int j=0;j<guo[shj[i].g].name.length();++j)
					if(guo[shj[i].g].name[j]!=' ')putchar(guo[shj[i].g].name[j]);
					if(t==-9)printf("生产了火枪。\n\n");
					if(t==-10)printf("生产了坦克。\n\n");
					if(t==-11)printf("发生了第一次工业革命。\n\n");
					if(t==-12)printf("发生了第二次工业革命。\n\n");
					if(t==-13)printf("发生了第三次工业革命。\n\n");
					if(t<0&&t>-9)printf("发生了革命，由%s转变为%s\n\n",uu[t<-5?-t-3:t<-2?2:-t-1].c_str(),uu[-t].c_str());
					if(t<0)continue;printf("打败了");
					for(int j=0;j<guo[t].name.length();++j)
					if(guo[t].name[j]!=' ')putchar(guo[t].name[j]);
					puts("\n");
				}
			}getch();getch();
		}
		/*if(t==5&&(tt==5||tt==6)&&(x==1||x==53)&&!si[1]&&!si[53]||
		t==5&&(tt==8)&&(x==1||x==2)&&!si[1]&&!si[2]){cls;
			for(int i=1;i<=(tt==8?2:53);i+=(tt==8?1:52))
			printf("%s 国力%d 兵力%d 军力%d 经济%d %s%d 政体%d 路程%d 预计%d\n",guo[i].name.c_str(),
			xg[i],xb[i],xj[i],xJ[i],guo[i].tu.c_str(),xt[i],xZ[i],tu[x][i],(xb[i]*xj[i]+tu[x][i]*10)/xj[x]+1);
			printf("侵略概率%d%%\n",gailv);
			puts("0国力赠送/索要\n1兵力赠送/索要\n2军力赠送/索要\n3经济赠送/索要\n4土地赠送/索要\n5政治赠送/索要\n6告诉下次侵略概率\n");
			int D=1e9,t=0,v,y=tt==8?3-x:54-x;
			for(int j=rev?cnt:1;rev?j:j<=cnt;rev?j--:j++)if(!si[j]&&j!=x&&j!=y)
			if(tu[y][j]<D)D=tu[y][j],t=j;
			printf("最有可能攻击%s(需要%d)\n",guo[t].name.c_str(),(xb[t]*xj[t]+tu[y][t]*10)/xj[y]+1);
			for(int j=rev?cnt:1;rev?j:j<=cnt;rev?j--:j++)if(!si[j]&&j!=x&&j!=y)
			if(tu[y][j]<=d1){printf("其次有可能攻击%s(需要%d)\n",guo[j].name.c_str(),(xb[j]*xj[j]+tu[y][j]*10)/xj[y]+1);break;}
			int u=getch()-48;if(u<0||u>6)return 0;
			cls;
			if(u==6){
				printf("当前概率%d%%\n输入新概率\n",gailv);
				scanf("%d",&gailv);Sleep(333);
			}
			if(u==0){
				printf("你的国力:%d 对方国力:%d\n输入赠送国力(负数表示索要)\n",xg[x],xg[y]);
				scanf("%d",&v);if(!v||xg[x]-v<0||xg[y]+v<0)puts("你不能这么做");
				else puts("操作成功"),xg[x]-=v,xg[y]+=v;Sleep(333);
			}
			if(u==5){
				printf("你的政治:%d 对方政治:%d\n输入赠送政治(负数表示索要)\n",xZ[x],xZ[y]);
				scanf("%d",&v);if(xZ[x]==xZ[y]||!v||(xZ[x]-xZ[y])*(xZ[x]-v-xZ[y]-v)<0)puts("你不能这么做");
				else puts("操作成功"),xZ[x]-=v,xZ[y]+=v;Sleep(333);
			}
			if(u==1){
				double ratio=1.*xj[x]/xj[y];
				printf("你的兵力:%d 对方兵力:%d\n输入赠送兵力(负数表示索要)\n"
				"注意:你的1兵力等于对方%lf兵力\n",xb[x],xb[y],ratio);
				scanf("%d",&v);int w=v*ratio;
				if(xb[x]==xb[y]||!v||(v>1||v<-1)&&(xb[x]-xb[y])*(xb[x]-v-xb[y]-w)<0)puts("你不能这么做");
				else if((xb[x]-xb[y])*(xb[x]-v-xb[y]-w)<0)
				(v==1?xb[y]=--xb[x]:xb[x]=--xb[y]),puts("操作成功");
				else puts("操作成功"),xb[x]-=v,xb[y]+=w;Sleep(333);
			}
			if(u==2){
				double ratio=1.*xb[x]/xb[y];
				printf("你的军力:%d 对方军力:%d\n输入赠送军力(负数表示索要)\n"
				"注意:你的1军力等于对方%lf军力\n",xj[x],xj[y],ratio);
				scanf("%d",&v);int w=v*ratio;
				if(xj[x]==xj[y]||!v||(v>1||v<-1)&&(xj[x]-xj[y])*(xj[x]-v-xj[y]-w)<0)puts("你不能这么做");
				else if((xj[x]-xj[y])*(xj[x]-v-xj[y]-w)<0)
				(v==1?xj[y]=--xj[x]:xj[x]=--xj[y]),puts("操作成功");
				else puts("操作成功"),xj[x]-=v,xj[y]+=w;Sleep(333);
			}
			if(u==3){
				double ratio=1.*xt[x]/xt[y];
				printf("你的经济:%d 对方经济:%d\n输入赠送经济(负数表示索要)\n"
				"注意:你的1经济等于对方%lf经济\n",xJ[x],xJ[y],ratio);
				scanf("%d",&v);int w=v*ratio;
				if(xJ[x]==xJ[y]||!v||(v>1||v<-1)&&(xJ[x]-xJ[y])*(xJ[x]-v-xJ[y]-w)<0)puts("你不能这么做");
				else if((xJ[x]-xJ[y])*(xJ[x]-v-xJ[y]-w)<0)
				(v==1?xJ[y]=--xJ[x]:xJ[x]=--xJ[y]),puts("操作成功");
				else puts("操作成功"),xJ[x]-=v,xJ[y]+=w;Sleep(333);
			}
			if(u==4){
				printf("你的土地:%d 对方土地:%d\n输入赠送土地(负数表示索要)\n",xt[x],xt[y]);
				scanf("%d",&v);if(xt[x]==xt[y]||!v||(xt[x]-xt[y])*(xt[x]-v-xt[y]-v)<0)puts("你不能这么做");
				else{
					puts("操作成功");
					if(v>0)xJ[y]=(xJ[y]*xt[y]+v*xJ[x])/(v+xt[y]);
					else xJ[x]=(xJ[x]*xt[x]-v*xJ[y])/(xt[x]-v);xt[y]+=v;xt[x]-=v;
				}
				Sleep(333);
			}
			return 0;
		}*/
		if(t==6){
			int vv[12]={0},ww[12]={0};
			for(int i=1;i<=cnt;i++)if(!si[i])vv[xT[i]]++;
			for(int i=0;i<9;i++)printf("%s %d\n",uu[i].c_str(),vv[i]);
			getch();getch();return 0;
		}
		if(t==7){
			printf("当前间隔：%d毫秒\n输入新间隔：",slp);
			scanf("%d",&slp);if(slp<0)slp=-slp;
			return 0;
		}
		if(t==0){
			if(tt==18||tt==19||tt==23){
			for(int i=1;i<=cnt;i++)if(tu[x][i]<100&&i!=x&&!si[i])
			printf("%s 国力%5d 兵力%4d 军力%4d 经济%4d %s%4d 政体%4d 路程%4d %4d 预计%4d ",guo[i].name.c_str(),
			xg[i],xb[i],xj[i],xJ[i],guo[i].tu.c_str(),xt[i],xZ[i],tu[x][i],tu[i][x],(xb[i]*xj[i]+tu[x][i]*10)/xj[x]+1),
			calc(i);
			for(int i=1;i<=cnt;i++)if(tu[x][i]>=100&&i!=x&&!si[i])
			printf("%s 国力%5d 兵力%4d 军力%4d 经济%4d %s%4d 政体%4d 路程%4d %4d 预计%4d ",guo[i].name.c_str(),
			xg[i],xb[i],xj[i],xJ[i],guo[i].tu.c_str(),xt[i],xZ[i],tu[x][i],tu[i][x],(xb[i]*xj[i]+tu[x][i]*10)/xj[x]+1),
			calc(i);
			}else
			for(int i=1;i<=cnt;i++)if(i!=x&&!si[i])
			printf("%s 国力%5d 兵力%4d 军力%4d 经济%4d %s%4d 政体%4d 路程%4d 预计%4d ",guo[i].name.c_str(),
			xg[i],xb[i],xj[i],xJ[i],guo[i].tu.c_str(),xt[i],xZ[i],tu[x][i],(xb[i]*xj[i]+tu[x][i]*10)/xj[x]+1),
			calc(i);
			getch();getch();getch();return 0;
		}
		if(t==-1){
			if(cnt>120)
			for(int i=1;i<=cnt;i++)if(tu[x][i]<100&&i!=x&&!si[i])
			printf("%s 国力%5d 兵力%4d 军力%4d 经济%4d %s%4d 政体%4d 路程%4d %4d 预计%4d ",guo[i].name.c_str(),
			xg[i],xb[i],xj[i],xJ[i],guo[i].tu.c_str(),xt[i],xZ[i],tu[x][i],tu[i][x],(xb[i]*xj[i]+tu[x][i]*10)/xj[x]+1),
			calc(i);if(cnt>120)getch(),getch(),getch();return 0;
		}
		if(t==-2){
			for(int j=1;j<=cnt;j++)if(!si[j]&&(j==x||fr[j][x])){
				for(int i=1;i<=cnt;i++)if(!si[i]&&calc(i,0)==j)printf("%s ",guo[i].name.c_str());printf("#%d\n",j);
				if(j!=x)printf("%s 国力%5d 兵力%4d 军力%4d 经济%4d %s%4d 政体%4d 路程%4d 预计%4d ",guo[j].name.c_str(),
				xg[j],xb[j],xj[j],xJ[j],guo[j].tu.c_str(),xt[j],xZ[j],tu[x][j],(xb[j]*xj[j]+tu[x][j]*10)/xj[x]+1),calc(j);
			}
			getch(),getch(),getch();return 0;
		}
		if(t==1){
			cls;
			printf("                选择你要进攻的%s\n\n\n\n\n       ",orz.c_str());
			int u=0,v,tot=0,w;
			for(int i=1;i<=cnt;i++){
				if(si[i]||i==x||fr[x][i])continue;++tot;
				printf("%d、%s ",tot,guo[i].name.c_str());
				du[tot]=i;
			}printf("\n\n           ");
			scanf("%d",&u);
			if(u<=0||u>tot){puts("  超过可攻打的范围！！！   ");Sleep(slp*2);return 0;}
			cls;printf("\n\n\n\n                  %s",guo[du[u]].name.c_str());
			printf("\n\n                兵力： %d   \n\n                %s： %d\n\n"
			"            路程消耗“ %d\n\n                预计： %d   "
			"\n\n\n        请输入你要入侵的%s(<=%d)（输入0返回）",xb[du[u]],guo[du[u]].tu.c_str(),
			xt[du[u]],tu[x][du[u]],(xb[du[u]]*xj[du[u]]+tu[x][du[u]]*10)/xj[x]+1,guo[du[u]].tu.c_str(),
			(xj[x]<15000?15:xT[x]==6?(xj[x]+15000)/2000:xj[x]/1000));scanf("%d",&v);
			if(v>(xj[x]<15000?15:xT[x]==6?(xj[x]+15000)/2000:xj[x]/1000)||v<=0||v>xt[du[u]]){puts("  超过可攻打的范围！！！   ");Sleep(slp*2);return 0;}
			printf("\n\n        请输入派出的兵力（输入0返回）");
			scanf("%d",&w);if(w<=0||w>xb[x]){puts("  没有足够的兵");Sleep(slp*2);return 0;}
			//if(tt==3&&x==5&&du[u]==7)xz[7]=0;
			if(typ&&!xz[x]&&xz[du[u]]){
				char ch[233];
				sprintf(ch,"我们加入了%s！！！！！！",xz[du[u]]==1?z2.c_str():z1.c_str());
				MessageBox(NULL,ch,"我国大事记",48);
				xz[x]=3-xz[du[u]];
			}
			if(typ&&xz[x]+xz[du[u]]!=3){
				MessageBox(NULL,"他们对我们宣战！！！！！！","我国大事记",48);
				if(xz[x])xz[du[u]]=3-xz[x];if(tt==4)sh[47]=1;
			}
			int z=vs(x,du[u],w);cls;
			if(z>0)printf("              战争胜利！！！%d",z);
			else printf("        战争失败！！！");Sleep(slp);
			if(z>0){
				xJ[x]=(xJ[x]*xt[x]+v*xJ[du[u]])/(v+xt[x]);xt[x]+=v;xt[du[u]]-=v;
			}
			if(xt[du[u]]<=0){cls;ev(x,du[u]); 
				printf("              %s战败！！！\n\n      ",guo[du[u]].name.c_str());
				Sleep(slp);
				for(int k=1;k<=cnt;k++)if(bj[k]==du[u])bj[k]=x;si[du[u]]=1;bj[du[u]]=x;
				if(ty)for(int k=1;k<=cnt;k++)tu[x][k]=min(tu[x][k],tu[du[u]][k]);
			}return 1;
		}
		if(t==2){
			cls;
			printf("\n\n\n\n\n               1、征兵\n\n               2、发展经济"
			"\n\n               3、发展战术\n\n               4、政治改良");
			int u,v;u=getch()-48;
			if(u<1||u>4)return 0;cls;
			ask(x,u);scanf("%d",&v);if(v>xg[x]||v<0)return 0;
			xg[x]-=v;add(x,u,v);Sleep(slp);return 0;
		}
		return t==3;
	}
	int t=rand()%100+1,T;
	if((xT[x]>5||xZ[x]>=6000)&&!typ||(tt==20&&x<9&&xT[x]>2))t=rand()%40+1;
	#define i
	if(cnt<120)cls;
	if((t>=0&&t<=25&&xg[x]>=100)||(typ&&xb[x]<guo[x].bingli&&t>40)){	
		T=xg[x];xg[x]=0;add(x,1,T);
	}
	if((t>25&&t<=30&&xg[x]>=200)||(typ&&xJ[x]<600&&t<50)){	
		T=xg[x];xg[x]=0;add(x,2,T);
	}
	if((typ&&xj[x]<400&&t>50)||(t>30&&t<(typ?60:40)&&xg[x]>=200)){
		T=xg[x];xg[x]=0;add(x,3,T);
	}
	if(!typ&&t>40&&xg[x]>=1000){
		T=xg[x];xg[x]=0;add(x,4,T);
	}
	if(cnt<120)printf("\n\n\n                 \n\n       %s      经济%d  军力     %d"
	,guo[x].name.c_str(),xJ[x],xj[x]);if(cnt<60)Sleep(slp);
	sj(x);if(tt==1)sj1(x);if(tt==3)sj2(x);if(tt==4)sj3(x);if(tt==23)sj4(x);
	if(tt==20&&!sh[1])if(si[1]+si[2]+si[3]+si[4]+si[5]+si[6]+si[7]+si[8]>=7){
		sh[1]=1;for(int I=1;I<=cnt;I++)for(int J=1;J<=cnt;J++)if(tu[I][J]>1e8)tu[I][J]=1500;
	}
	if(typ&&xz[x]==0)return 0;
	t=rand()%100+1;
	//if((tt==5||tt==6)&&(x==1||x==53)&&!si[1]&&!si[53]||(tt==8||tt==17||tt==21)&&(x==1||x==2)&&!si[1]&&!si[2])
	//if(rand()%100<gailv)t=t*5%100+5;else t=3;
	if(!typ&&t%5)return 0;
	if(tt==3)
	if(((Y>1941&&t>=40)||t>80||(xz[x]==2&&t>20))||(x==8&&xt[8]<=150)&&xb[x]>50);else return 0;
	if(tt==4)
	if((xz[x]==1&&t<=20)||(xz[x]==2&&t<=35))return 0;
	int z=1e9,u=0;
	for(int j=rev?cnt:1;rev?j:j<=cnt;rev?j--:j++){
		if(si[j]||j==x||(typ&&xz[x]==xz[j])||(typ&&xz[j]==0)||xb[x]*xj[x]/18<tu[x][j])continue;
		if(tt==4)
		if(x*j==19&&x+j==20&&Y==2016&&M<=2)continue;
		if(tt==3)
		if((x==8&&j==16&&xz[5]==0&&!si[5])||
		(x==13&&j!=10&&!si[10])||(x==8&&j!=5&&!si[5]&&xt[5]>150&&xz[5]==1))continue;
		if(fr[x][j])continue;
		if(z>tu[x][j])z=tu[x][j],u=j;
		if(t<=20&&tu[x][j]<d1){z=tu[x][j],u=j;break;}
		if(t>90&&tu[x][j]>d2&&(cnt<120||xt[x]<=15)){z=tu[x][j],u=j;break;}
	}if(u==0)return 0;
	if(u==p1||u==p2){
		cls;printf("\n\n\n               %s向%s发起侵略！！！",guo[x].name.c_str(),dr?"我们":u==p1?"1P":"2P");
		Sleep(slp*4);
		int z=vs(x,u,xb[x]/2);cls;
		if(z>0)printf("              战争失败！！！");
		else printf("        战争胜利！！！");Sleep(slp);
		if(z>0){
			int v=xt[u]>(xj[x]<15000?15:xT[x]==6?(xj[x]+15000)/2000:xj[x]/1000)?(xj[x]<15000?15:xT[x]==6?(xj[x]+15000)/2000:xj[x]/1000):xt[u];
			xJ[x]=(xJ[x]*xt[x]+v*xJ[u])/(v+xt[x]);xt[x]+=v;xt[u]-=v;
		}
		if(xt[u]<=0){cls;
			for(int k=1;k<=cnt;k++)if(bj[k]==u)bj[k]=x;si[u]=1;bj[u]=x;
			if(ty)for(int k=1;k<=cnt;k++)tu[x][k]=min(tu[x][k],tu[u][k]);Sleep(slp);cls;
			printf("\n\n\n                  %s方%s全部沦陷！！！  游戏结束！！！\n\n\n\n                    ",
			dr?"我":u==p1?"1P":"2P",guo[u].tu.c_str());
			if(dr||si[p1]&&si[p2])lo=1;Sleep(slp*6);ev(x,u);
		}return 1;
	}z=vs(x,u,xb[x]/2);
	if(cnt<120||fr[x][p1]||fr[x][p2]||fr[u][p1]||fr[u][p2])
	cls,printf("\n\n\n               %s  和   %s   发生了战争",guo[x].name.c_str(),guo[u].name.c_str()),
	Sleep(slp);
	if(cnt<120||fr[x][p1]||fr[x][p2]||fr[u][p1]||fr[u][p2])
	cls,printf("\n\n                   %s赢得了胜利！！！",z>0?guo[x].name.c_str():guo[u].name.c_str()),
	Sleep(slp),cls;
	if(z>0){
		int v=xt[u]>(xj[x]<15000?15:xT[x]==6?(xj[x]+15000)/2000:xj[x]/1000)?(xj[x]<15000?15:xT[x]==6?(xj[x]+15000)/2000:xj[x]/1000):xt[u];
		xJ[x]=(xJ[x]*xt[x]+v*xJ[u])/(v+xt[x]);xt[x]+=v;xt[u]-=v;
	}
	if(xt[u]<=0){cls;
		for(int k=1;k<=cnt;k++)if(bj[k]==u)bj[k]=x;si[u]=1;bj[u]=x;
		if(ty)for(int k=1;k<=cnt;k++)tu[x][k]=min(tu[x][k],tu[u][k]);
		if(cnt<120)
		printf("              %s战败！！！\n\n      ",guo[u].name.c_str());
		else
		printf("              %s被%s击败！！！\n\n  ",guo[u].name.c_str(),guo[x].name.c_str());
		Sleep(slp);ev(x,u);
	}
	#undef i
}
#define scan(...) fscanf(__,__VA_ARGS__)
int main(){gailv=20;lo=0;srand(time(0));int js=0;bool player1_win=0,player2_win=0;
	printf("\n\n\n                 战争世界        \n\n                0、读档\n\n"
	"                1、春秋纷争\n\n                2、中世纪欧洲\n\n                "
	"3、二次世界大战\n\n                4、2016届绍兴一中信奥班"
	"\n\n                5、初中杀\n\n                6、初中杀（2个班）"
	"\n\n                7、一二八恶性斗殴\n\n                8、初高中杀（共4个班）"
	"\n\n                9、单挑NiroBC\n\n                A、初高中杀（共8个班）"
	"\n\n                B、2016届绍兴一中学生\n\n                C、绍兴一中老师"
	"\n\n                D、GEL teachers\n\n                E、初高中杀（共8个班，鲁毅涛版）"
	"\n\n                F、2016届（13）班杀\n\n                G、2016届绍兴一中学生&绍兴一中老师（可能人有点多需耗较长时间）"
	);
	int T=getchar()-48;cnt=0;if(T>48)T-=32;tt=T;
	if(tt==0){
		FILE*__=fopen("a","r");lo=0;
scan("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&T,&cnt,&typ,&ty,&d1,&d2,&_,&Y,&M,&W,&YY,&MM,&WW,&p1,&p2,&dr,&gailv);
		tt=T;
		char x[233],y[233],z[233];scan("%s%s%s",&x,&y,&z);
		orz=x;z1=y;z2=z;
		for(int i=1;i<=1200;i++)scan("%d",&sh[i]);
		for(int i=1;i<=cnt;i++)scan("%d%d%d%d%d%d%d%d%d%d%d%d%d",
		&du[i],&xz[i],&q[i],&bj[i],&xg[i],&xb[i],&xj[i],&xJ[i],&xt[i],&xT[i],&xZ[i],&si[i],&gg[i]);
		for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++)scan("%d",&tu[i][j]),
		(tu[i][j]<0?tu[i][j]=-tu[i][j],fr[i][j]=1:0);
		for(int i=1;i<=cnt;i++)scan("%s%d%d%d%d%d%d%d%d%s",
		x,&guo[i].guoli,&guo[i].bingli,&guo[i].junli,&guo[i].jingji,
		&guo[i].tudi,&guo[i].zhengzhi,&guo[i].tizhi,&guo[i].zhen,y),guo[i].name=x,guo[i].tu=y;
		int order;scan("%d%d%d",&order,&rev,&cn);
		for(int i=1;i<=cn;i++)scan("%d%d%d%d%d",&shj[i].y,&shj[i].m,&shj[i].w,&shj[i].g,&shj[i].t);
		if(T==5||T==6||T==8||T==17||T==21||T==22){
			for(int i=1;i<=cnt;i++)if(guo[i].name.size()<6)guo[i].name=guo[i].name+"  ";
			for(int i=1;i<=cnt;i++)if(guo[i].tu.size()<4)guo[i].tu="  "+guo[i].tu;
		}
		if(T==18){
			for(int i=1;i<=cnt;i++)while(guo[i].name.size()<8)guo[i].name=guo[i].name+"  ";
			for(int i=1;i<=cnt;i++)if(guo[i].tu.size()<4)guo[i].tu="  "+guo[i].tu;
		}fclose(__);if(order==1)goto pp0;else goto pp1;
	}
	puts("是否双人??");
	dr=getchar();while(dr<=32)dr=getchar();dr&=1;dr^=1;cls; 
	//dr=MessageBox(NULL,"是否双人","模式",4)-6;
	if(T==6||T==5){cnt=T==6?107:54;orz="同学";typ=0;ty=1;d1=20;d2=40;_=0;rev=0;fr[1][53]=fr[53][1]=1;
guo[1].name="鲍东方";
guo[2].name="陈雨珂";
guo[3].name="傅俊杰";
guo[4].name="胡凯捷";
guo[5].name="劳伊栋";
guo[6].name="李之琦";
guo[7].name="鲁含彬";
guo[8].name="马畅  ";
guo[9].name="茅明煜";
guo[10].name="孟晨沛";
guo[11].name="宋清哲";
guo[12].name="屠世超";
guo[13].name="王一涛";
guo[14].name="徐晟  ";
guo[15].name="杨三川";
guo[16].name="杨怿驰";
guo[17].name="余笑容";
guo[18].name="俞快  ";
guo[19].name="张冲  ";
guo[20].name="章千龙";
guo[21].name="章宇飞";
guo[22].name="赵乐毅";
guo[23].name="周子杰";
guo[24].name="曹紫艳";
guo[25].name="陈澜  ";
guo[26].name="陈思妤";
guo[27].name="单田田";
guo[28].name="冯嘉敏";
guo[29].name="傅露怡";
guo[30].name="高雨辰";
guo[31].name="洪珂凡";
guo[32].name="洪雯欣";
guo[33].name="胡馨丹";
guo[34].name="鲁奕宁";
guo[35].name="孟妍楠";
guo[36].name="沈伊清";
guo[37].name="汪心妍";
guo[38].name="王佳乐";
guo[39].name="王佳颖";
guo[40].name="王如栩";
guo[41].name="吴闻庭";
guo[42].name="徐涵纯";
guo[43].name="徐洁  ";
guo[44].name="严思瑶";
guo[45].name="张彬涵";
guo[46].name="谢林悦";
guo[47].name="张许诺";
guo[48].name="张旭  ";
guo[49].name="张羿  ";
guo[50].name="章天栩";
guo[51].name="章晔倚";
guo[52].name="赵瑾毅";
guo[53].name="祝欣妍（猪妖为什么这么强）";
guo[54].name="郭卓远";
guo[55].name="安韬  ";
guo[56].name="班越童";
guo[57].name="陈禹枫";
guo[58].name="单弘扬";
guo[59].name="丁天烨";
guo[60].name="董泽杭";
guo[61].name="冯诚君";
guo[62].name="黄飞扬";
guo[63].name="李斯泽";
guo[64].name="陆潘安";
guo[65].name="马书立";
guo[66].name="秦天楷";
guo[67].name="裘坤樑";
guo[68].name="陶烨  ";
guo[69].name="王瀚加";
guo[70].name="王济源";
guo[71].name="王柯杰";
guo[72].name="王伊宁";
guo[73].name="吴昊天";
guo[74].name="姚嘉程";
guo[75].name="余晨阳";
guo[76].name="詹洪涛";
guo[77].name="赵一  ";
guo[78].name="钟成杰";
guo[79].name="周易  ";
guo[80].name="陈佳瀛";
guo[81].name="陈欣瑜";
guo[82].name="陈妍羽";
guo[83].name="陈奕林";
guo[84].name="董之瑜";
guo[85].name="郭祎婧";
guo[86].name="胡楷其";
guo[87].name="胡昕怡";
guo[88].name="蒋卓颖";
guo[89].name="金晟  ";
guo[90].name="李笑笑";
guo[91].name="沈天逸";
guo[92].name="沈卓琼";
guo[93].name="史尊仪";
guo[94].name="宋琦  ";
guo[95].name="屠靖靖";
guo[96].name="屠蕊林";
guo[97].name="汪悦琦";
guo[98].name="王嘉颖";
guo[99].name="王珂芸";
guo[100].name="王卿瑜";
guo[101].name="吴旻  ";
guo[102].name="徐如鸿";
guo[103].name="徐恬恬";
guo[104].name="杨佳文";
guo[105].name="张优佳";
guo[106].name="章宁尔";
guo[107].name="金一冰";
for(int i=1;i<=cnt;i++)for(int j=i+1;j<=cnt;j++){
	tu[i][j]=tu[j][i]=rand()%90+10;
	if(i<=54&&j>54)tu[i][j]+=200,tu[j][i]+=200;
}
for(i=1;i<=cnt;i++)guo[i]={guo[i].name,"",200,50,50,50,61,50,0,0};
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			sh[i]=0;du[i]=0;xz[i]=0;q[i]=0;bj[i]=i;xT[i]=0;gg[i]=0;si[i]=0;
			guo[i].tu=guo[i].name[4]==' '?guo[i].name.substr(2,2):guo[i].name.substr(4,2);
			guo[i].tu+="土";
			if(i==28||i==31||i==32||i==33||i==41||i==44||i==48||i==52)guo[i].tu="妖土";
			if(i==1||i==53)guo[i].tu="  土";
			if(i==5||i==104)guo[i].tu="死土";
			if(i==13||i==67||i==36||i==51)guo[i].tu="猪土";
			if(i==14)guo[i].tu="狗土";
		}Y=2013;M=9;W=-1;YY=0;MM=0;WW=8-T;
	}
if(T==8){cnt=213;orz="同学";typ=0;ty=1;d1=20;d2=40;_=0;rev=1;fr[1][2]=fr[2][1]=1;
	int type[1024];
guo[1].name="鲍东方";type[1]=5;
guo[2].name="祝欣妍（猪妖为什么这么强）";type[2]=5;
guo[3].name="陈雨珂";type[3]=1;
guo[4].name="傅俊杰";type[4]=1;
guo[5].name="胡凯捷";type[5]=1;
guo[6].name="劳伊栋";type[6]=1;
guo[7].name="李之琦";type[7]=1;
guo[8].name="鲁含彬";type[8]=1;
guo[9].name="马畅  ";type[9]=1;
guo[10].name="茅明煜";type[10]=1;
guo[11].name="孟晨沛";type[11]=1;
guo[12].name="宋清哲";type[12]=1;
guo[13].name="屠世超";type[13]=1;
guo[14].name="王一涛";type[14]=1;
guo[15].name="徐晟  ";type[15]=1;
guo[16].name="杨三川";type[16]=1;
guo[17].name="杨怿驰";type[17]=1;
guo[18].name="余笑容";type[18]=1;
guo[19].name="俞快  ";type[19]=5;
guo[20].name="张冲  ";type[20]=1;
guo[21].name="章千龙";type[21]=1;
guo[22].name="章宇飞";type[22]=1;
guo[23].name="赵乐毅";type[23]=5;
guo[24].name="周子杰";type[24]=1;
guo[25].name="曹紫艳";type[25]=1;
guo[26].name="陈澜  ";type[26]=1;
guo[27].name="陈思妤";type[27]=1;
guo[28].name="单田田";type[28]=1;
guo[29].name="冯嘉敏";type[29]=1;
guo[30].name="傅露怡";type[30]=1;
guo[31].name="高雨辰";type[31]=1;
guo[32].name="洪珂凡";type[32]=9;
guo[33].name="洪雯欣";type[33]=1;
guo[34].name="胡馨丹";type[34]=1;
guo[35].name="鲁奕宁";type[35]=1;
guo[36].name="孟妍楠";type[36]=1;
guo[37].name="沈伊清";type[37]=1;
guo[38].name="汪心妍";type[38]=1;
guo[39].name="王佳乐";type[39]=1;
guo[40].name="王佳颖";type[40]=1;
guo[41].name="王如栩";type[41]=1;
guo[42].name="吴闻庭";type[42]=1;
guo[43].name="徐涵纯";type[43]=1;
guo[44].name="徐洁  ";type[44]=1;
guo[45].name="严思瑶";type[45]=1;
guo[46].name="张彬涵";type[46]=1;
guo[47].name="谢林悦";type[47]=1;
guo[48].name="张许诺";type[48]=1;
guo[49].name="张旭  ";type[49]=1;
guo[50].name="张羿  ";type[50]=1;
guo[51].name="章天栩";type[51]=1;
guo[52].name="章晔倚";type[52]=1;
guo[53].name="赵瑾毅";type[53]=1;
guo[54].name="郭卓远";type[54]=1;
guo[55].name="安韬  ";type[55]=2;
guo[56].name="班越童";type[56]=2;
guo[57].name="陈禹枫";type[57]=2;
guo[58].name="单弘扬";type[58]=2;
guo[59].name="丁天烨";type[59]=2;
guo[60].name="董泽杭";type[60]=2;
guo[61].name="冯诚君";type[61]=2;
guo[62].name="黄飞扬";type[62]=2;
guo[63].name="李斯泽";type[63]=2;
guo[64].name="陆潘安";type[64]=2;
guo[65].name="马书立";type[65]=2;
guo[66].name="秦天楷";type[66]=2;
guo[67].name="裘坤樑";type[67]=2;
guo[68].name="陶烨  ";type[68]=2;
guo[69].name="王瀚加";type[69]=2;
guo[70].name="王济源";type[70]=2;
guo[71].name="王柯杰";type[71]=2;
guo[72].name="王伊宁";type[72]=2;
guo[73].name="吴昊天";type[73]=2;
guo[74].name="姚嘉程";type[74]=10;
guo[75].name="余晨阳";type[75]=2;
guo[76].name="詹洪涛";type[76]=2;
guo[77].name="赵一  ";type[77]=2;
guo[78].name="钟成杰";type[78]=2;
guo[79].name="周易  ";type[79]=2;
guo[80].name="陈佳瀛";type[80]=2;
guo[81].name="陈欣瑜";type[81]=2;
guo[82].name="陈妍羽";type[82]=2;
guo[83].name="陈奕林";type[83]=2;
guo[84].name="董之瑜";type[84]=2;
guo[85].name="郭祎婧";type[85]=2;
guo[86].name="胡楷其";type[86]=2;
guo[87].name="胡昕怡";type[87]=2;
guo[88].name="蒋卓颖";type[88]=2;
guo[89].name="金晟  ";type[89]=2;
guo[90].name="李笑笑";type[90]=2;
guo[91].name="沈天逸";type[91]=2;
guo[92].name="沈卓琼";type[92]=2;
guo[93].name="史尊仪";type[93]=2;
guo[94].name="宋琦  ";type[94]=2;
guo[95].name="屠靖靖";type[95]=2;
guo[96].name="屠蕊林";type[96]=2;
guo[97].name="汪悦琦";type[97]=2;
guo[98].name="王嘉颖";type[98]=2;
guo[99].name="王珂芸";type[99]=2;
guo[100].name="王卿瑜";type[100]=2;
guo[101].name="吴旻  ";type[101]=2;
guo[102].name="徐如鸿";type[102]=2;
guo[103].name="徐恬恬";type[103]=2;
guo[104].name="杨佳文";type[104]=2;
guo[105].name="张优佳";type[105]=2;
guo[106].name="章宁尔";type[106]=2;
guo[107].name="金一冰";type[107]=2;
guo[108].name="包菁菁";type[108]=4;
guo[109].name="包灵怡";type[109]=4;
guo[110].name="车央菲";type[110]=4;
guo[111].name="丁奇瑶";type[111]=4;
guo[112].name="傅依雯";type[112]=4;
guo[113].name="韩慧瑜";type[113]=4;
guo[114].name="何心仪";type[114]=4;
guo[115].name="胡寒昱";type[115]=4;
guo[116].name="黄嘉宝";type[116]=4;
guo[117].name="金庭冉";type[117]=4;
guo[118].name="楼家宁";type[118]=4;
guo[119].name="鲁意  ";type[119]=4;
guo[120].name="沈贺蕾";type[120]=4;
guo[121].name="沈雯怡";type[121]=4;
guo[122].name="沈熠  ";type[122]=4;
guo[123].name="水丹枫";type[123]=4;
guo[124].name="陶忻妤";type[124]=4;
guo[125].name="谢世莹";type[125]=4;
guo[126].name="薛鸽  ";type[126]=4;
guo[127].name="杨羽琪";type[127]=4;
guo[128].name="俞逸凡";type[128]=4;
guo[129].name="张滢  ";type[129]=4;
guo[130].name="祝元仪";type[130]=4;
guo[131].name="陈龙翀";type[131]=4;
guo[132].name="陈齐治";type[132]=4;
guo[133].name="陈启楠";type[133]=4;
guo[134].name="褚步霄";type[134]=4;
guo[135].name="邓仁杰";type[135]=4;
guo[136].name="方震  ";type[136]=4;
guo[137].name="傅乐天";type[137]=4;
guo[138].name="郭楠  ";type[138]=4;
guo[139].name="何晨泽";type[139]=4;
guo[140].name="金天宇";type[140]=4;
guo[141].name="李家成";type[141]=4;
guo[142].name="任和  ";type[142]=4;
guo[143].name="沈序戎";type[143]=4;
guo[144].name="寿家跃";type[144]=4;
guo[145].name="田振楠";type[145]=4;
guo[146].name="王天乐";type[146]=4;
guo[147].name="王轩宇";type[147]=4;
guo[148].name="王雨辰";type[148]=4;
guo[149].name="王子习";type[149]=4;
guo[150].name="吴泽棋";type[150]=4;
guo[151].name="徐希彦";type[151]=4;
guo[152].name="俞鸿飞";type[152]=4;
guo[153].name="虞快  ";type[153]=4;
guo[154].name="詹致豪";type[154]=4;
guo[155].name="张乐行";type[155]=4;
guo[156].name="张逸凡";type[156]=4;
guo[157].name="周程扬";type[157]=4;
guo[158].name="朱洲明";type[158]=4;
guo[159].name="祝元泽";type[159]=4;
guo[160].name="张逸涛";type[160]=4;
guo[161].name="董恬恬";type[161]=8;
guo[162].name="杜晗晨";type[162]=8;
guo[163].name="傅雪艺";type[163]=8;
guo[164].name="顾依珂";type[164]=8;
guo[165].name="何楚楚";type[165]=8;
guo[166].name="何雪雯";type[166]=8;
guo[167].name="胡琳妍";type[167]=8;
guo[168].name="黄睿琳";type[168]=8;
guo[169].name="李浙湘";type[169]=8;
guo[170].name="钱胜男";type[170]=8;
guo[171].name="裘思远";type[171]=8;
guo[172].name="沈静怡";type[172]=8;
guo[173].name="石沁  ";type[173]=8;
guo[174].name="宋雯睿";type[174]=8;
guo[175].name="宋妤恬";type[175]=8;
guo[176].name="陶婷婷";type[176]=8;
guo[177].name="陶叶雨";type[177]=8;
guo[178].name="王思妍";type[178]=8;
guo[179].name="谢燚莹";type[179]=8;
guo[180].name="徐童瑶";type[180]=8;
guo[181].name="殷晗放";type[181]=8;
guo[182].name="尹麒惠";type[182]=8;
guo[183].name="袁佳菲";type[183]=8;
guo[184].name="袁益瑜";type[184]=8;
guo[185].name="张嘉琦";type[185]=8;
guo[186].name="张雨倩";type[186]=8;
guo[187].name="周宇婷";type[187]=8;
guo[188].name="诸梦琴";type[188]=8;
guo[189].name="鲍荣瑜";type[189]=8;
guo[190].name="曹成灿";type[190]=8;
guo[191].name="陈立  ";type[191]=8;
guo[192].name="黄勇  ";type[192]=8;
guo[193].name="江子焕";type[193]=8;
guo[194].name="金涛杰";type[194]=8;
guo[195].name="鲁毅涛";type[195]=8;
guo[196].name="鲁煜恺";type[196]=8;
guo[197].name="施熠辉";type[197]=8;
guo[198].name="宋世煜";type[198]=8;
guo[199].name="苏修远";type[199]=8;
guo[200].name="孙博波";type[200]=8;
guo[201].name="陶晨阳";type[201]=8;
guo[202].name="王彬  ";type[202]=8;
guo[203].name="王颖杰";type[203]=8;
guo[204].name="王宇龙";type[204]=8;
guo[205].name="吴涵  ";type[205]=8;
guo[206].name="夏泽楷";type[206]=8;
guo[207].name="谢泽栋";type[207]=8;
guo[208].name="袁晟轶";type[208]=8;
guo[209].name="张飞跃";type[209]=8;
guo[210].name="张泠璞";type[210]=8;
guo[211].name="周卓效";type[211]=8;
guo[212].name="朱力宇";type[212]=8;
guo[213].name="祝嘉君";type[213]=8;
for(int i=1;i<=cnt;i++)for(int j=i+1;j<=cnt;j++){
	tu[i][j]=tu[j][i]=rand()%90+10;
	if(i<=2)tu[i][j]++,tu[j][i]++;
	if(type[i]&type[j]);
	else if((3&type[i])&&(3&type[j])||(12&type[i])&&(12&type[j]))tu[i][j]+=200,tu[j][i]+=200;
	else tu[i][j]+=1200,tu[j][i]+=1200;
}
for(i=1;i<=cnt;i++)guo[i]={guo[i].name,"",200,50,50,50,61,50,0,0};
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			sh[i]=0;du[i]=0;xz[i]=0;q[i]=0;bj[i]=i;xT[i]=0;gg[i]=0;si[i]=0;
			guo[i].tu=guo[i].name.length()<=4||guo[i].name[4]==' '?guo[i].name.substr(2,2):guo[i].name.substr(4,2);
			guo[i].tu+="土";
			if(i==29||i==32||i==33||i==34||i==42||i==45||i==49||i==53)guo[i].tu="妖土";
			if(i==1||i==2)guo[i].tu="  土";
			if(i==6||i==104||i==156)guo[i].tu="死土";
			if(i==14||i==67||i==37||i==52)guo[i].tu="猪土";
			if(i==15)guo[i].tu="狗土";
		}Y=2013;M=9;W=0;YY=0;MM=0;WW=1;
}
if(T==17||T==21){
	cnt=T==17?415:425;orz="同学";typ=0;ty=1;d1=20;d2=40;_=0;rev=1;fr[1][2]=fr[2][1]=1;
	int type[1024];
guo[1].name="鲍东方";type[1]=533;
guo[2].name="祝欣妍（猪妖为什么这么强）";type[2]=5;
guo[3].name="陈雨珂";type[3]=1;
guo[4].name="傅俊杰";type[4]=1;
guo[5].name="胡凯捷";type[5]=17;
guo[6].name="劳伊栋";type[6]=1;
guo[7].name="李之琦";type[7]=1;
guo[8].name="鲁含彬";type[8]=1;
guo[9].name="马畅  ";type[9]=1;
guo[10].name="茅明煜";type[10]=1;
guo[11].name="孟晨沛";type[11]=1;
guo[12].name="宋清哲";type[12]=1;
guo[13].name="屠世超";type[13]=1;
guo[14].name="王一涛";type[14]=1;
guo[15].name="徐晟  ";type[15]=1;
guo[16].name="杨三川";type[16]=1;
guo[17].name="杨怿驰";type[17]=1;
guo[18].name="余笑容";type[18]=1;
guo[19].name="俞快  ";type[19]=5;
guo[20].name="张冲  ";type[20]=1;
guo[21].name="章千龙";type[21]=1;
guo[22].name="章宇飞";type[22]=1;
guo[23].name="赵乐毅";type[23]=533;
guo[24].name="周子杰";type[24]=1;
guo[25].name="曹紫艳";type[25]=1;
guo[26].name="陈澜  ";type[26]=1;
guo[27].name="陈思妤";type[27]=1;
guo[28].name="单田田";type[28]=1;
guo[29].name="冯嘉敏";type[29]=1;
guo[30].name="傅露怡";type[30]=1;
guo[31].name="高雨辰";type[31]=1;
guo[32].name="洪珂凡";type[32]=137;
guo[33].name="洪雯欣";type[33]=1;
guo[34].name="胡馨丹";type[34]=1;
guo[35].name="鲁奕宁";type[35]=1;
guo[36].name="孟妍楠";type[36]=1;
guo[37].name="沈伊清";type[37]=1;
guo[38].name="汪心妍";type[38]=1;
guo[39].name="王佳乐";type[39]=1;
guo[40].name="王佳颖";type[40]=1;
guo[41].name="王如栩";type[41]=1;
guo[42].name="吴闻庭";type[42]=1;
guo[43].name="徐涵纯";type[43]=1;
guo[44].name="徐洁  ";type[44]=1;
guo[45].name="严思瑶";type[45]=1;
guo[46].name="张彬涵";type[46]=1;
guo[47].name="谢林悦";type[47]=1;
guo[48].name="张许诺";type[48]=1;
guo[49].name="张旭  ";type[49]=1;
guo[50].name="张羿  ";type[50]=1;
guo[51].name="章天栩";type[51]=1;
guo[52].name="章晔倚";type[52]=1;
guo[53].name="赵瑾毅";type[53]=1;
guo[54].name="郭卓远";type[54]=1;
guo[55].name="安韬  ";type[55]=2;
guo[56].name="班越童";type[56]=514;
guo[57].name="陈禹枫";type[57]=2;
guo[58].name="单弘扬";type[58]=2;
guo[59].name="丁天烨";type[59]=2;
guo[60].name="董泽杭";type[60]=2;
guo[61].name="冯诚君";type[61]=18;
guo[62].name="黄飞扬";type[62]=2;
guo[63].name="李斯泽";type[63]=2;
guo[64].name="陆潘安";type[64]=2;
guo[65].name="马书立";type[65]=2;
guo[66].name="秦天楷";type[66]=2;
guo[67].name="裘坤樑";type[67]=2;
guo[68].name="陶烨  ";type[68]=2;
guo[69].name="王瀚加";type[69]=2;
guo[70].name="王济源";type[70]=2;
guo[71].name="王柯杰";type[71]=2;
guo[72].name="王伊宁";type[72]=2;
guo[73].name="吴昊天";type[73]=2;
guo[74].name="姚嘉程";type[74]=538;
guo[75].name="余晨阳";type[75]=2;
guo[76].name="詹洪涛";type[76]=2;
guo[77].name="赵一  ";type[77]=2;
guo[78].name="钟成杰";type[78]=2;
guo[79].name="周易  ";type[79]=2;
guo[80].name="陈佳瀛";type[80]=2;
guo[81].name="陈欣瑜";type[81]=2;
guo[82].name="陈妍羽";type[82]=2;
guo[83].name="陈奕林";type[83]=2;
guo[84].name="董之瑜";type[84]=2;
guo[85].name="郭祎婧";type[85]=2;
guo[86].name="胡楷其";type[86]=2;
guo[87].name="胡昕怡";type[87]=2;
guo[88].name="蒋卓颖";type[88]=2;
guo[89].name="金晟  ";type[89]=2;
guo[90].name="李笑笑";type[90]=66;
guo[91].name="沈天逸";type[91]=2;
guo[92].name="沈卓琼";type[92]=2;
guo[93].name="史尊仪";type[93]=2;
guo[94].name="宋琦  ";type[94]=34;
guo[95].name="屠靖靖";type[95]=2;
guo[96].name="屠蕊林";type[96]=2;
guo[97].name="汪悦琦";type[97]=2;
guo[98].name="王嘉颖";type[98]=2;
guo[99].name="王珂芸";type[99]=2;
guo[100].name="王卿瑜";type[100]=2;
guo[101].name="吴旻  ";type[101]=2;
guo[102].name="徐如鸿";type[102]=130;
guo[103].name="徐恬恬";type[103]=2;
guo[104].name="杨佳文";type[104]=2;
guo[105].name="张优佳";type[105]=2;
guo[106].name="章宁尔";type[106]=2;
guo[107].name="金一冰";type[107]=2;
guo[108].name="包菁菁";type[108]=132;
guo[109].name="包灵怡";type[109]=532;
guo[110].name="车央菲";type[110]=548;
guo[111].name="丁奇瑶";type[111]=132;
guo[112].name="傅依雯";type[112]=532;
guo[113].name="韩慧瑜";type[113]=4;
guo[114].name="何心仪";type[114]=4;
guo[115].name="胡寒昱";type[115]=4;
guo[116].name="黄嘉宝";type[116]=4;
guo[117].name="金庭冉";type[117]=4;
guo[118].name="楼家宁";type[118]=4;
guo[119].name="鲁意  ";type[119]=4;
guo[120].name="沈贺蕾";type[120]=132;
guo[121].name="沈雯怡";type[121]=548;
guo[122].name="沈熠  ";type[122]=132;
guo[123].name="水丹枫";type[123]=68;
guo[124].name="陶忻妤";type[124]=4;
guo[125].name="谢世莹";type[125]=4;
guo[126].name="薛鸽  ";type[126]=4;
guo[127].name="杨羽琪";type[127]=4;
guo[128].name="俞逸凡";type[128]=68;
guo[129].name="张滢  ";type[129]=4;
guo[130].name="祝元仪";type[130]=4;
guo[131].name="陈龙翀";type[131]=532;
guo[132].name="陈齐治";type[132]=20;
guo[133].name="陈启楠";type[133]=4;
guo[134].name="褚步霄";type[134]=532;
guo[135].name="邓仁杰";type[135]=4;
guo[136].name="方震  ";type[136]=20;
guo[137].name="傅乐天";type[137]=532;
guo[138].name="郭楠  ";type[138]=532;
guo[139].name="何晨泽";type[139]=20;
guo[140].name="金天宇";type[140]=4;
guo[141].name="李家成";type[141]=20;
guo[142].name="任和  ";type[142]=4;
guo[143].name="沈序戎";type[143]=532;
guo[144].name="寿家跃";type[144]=532;
guo[145].name="田振楠";type[145]=532;
guo[146].name="王天乐";type[146]=20;
guo[147].name="王轩宇";type[147]=4;
guo[148].name="王雨辰";type[148]=4;
guo[149].name="王子习";type[149]=20;
guo[150].name="吴泽棋";type[150]=4;
guo[151].name="徐希彦";type[151]=20;
guo[152].name="俞鸿飞";type[152]=532;
guo[153].name="虞快  ";type[153]=20;
guo[154].name="詹致豪";type[154]=532;
guo[155].name="张乐行";type[155]=532;
guo[156].name="张逸凡";type[156]=532;
guo[157].name="周程扬";type[157]=532;
guo[158].name="朱洲明";type[158]=4;
guo[159].name="祝元泽";type[159]=132;
guo[160].name="张逸涛";type[160]=68;
guo[161].name="董恬恬";type[161]=8;
guo[162].name="杜晗晨";type[162]=8;
guo[163].name="傅雪艺";type[163]=8;
guo[164].name="顾依珂";type[164]=72;
guo[165].name="何楚楚";type[165]=552;
guo[166].name="何雪雯";type[166]=8;
guo[167].name="胡琳妍";type[167]=552;
guo[168].name="黄睿琳";type[168]=8;
guo[169].name="李浙湘";type[169]=8;
guo[170].name="钱胜男";type[170]=8;
guo[171].name="裘思远";type[171]=136;
guo[172].name="沈静怡";type[172]=8;
guo[173].name="石沁  ";type[173]=136;
guo[174].name="宋雯睿";type[174]=136;
guo[175].name="宋妤恬";type[175]=72;
guo[176].name="陶婷婷";type[176]=8;
guo[177].name="陶叶雨";type[177]=136;
guo[178].name="王思妍";type[178]=8;
guo[179].name="谢燚莹";type[179]=8;
guo[180].name="徐童瑶";type[180]=8;
guo[181].name="殷晗放";type[181]=8;
guo[182].name="尹麒惠";type[182]=8;
guo[183].name="袁佳菲";type[183]=8;
guo[184].name="袁益瑜";type[184]=72;
guo[185].name="张嘉琦";type[185]=40;
guo[186].name="张雨倩";type[186]=8;
guo[187].name="周宇婷";type[187]=72;
guo[188].name="诸梦琴";type[188]=40;
guo[189].name="鲍荣瑜";type[189]=8;
guo[190].name="曹成灿";type[190]=8;
guo[191].name="陈立  ";type[191]=8;
guo[192].name="黄勇  ";type[192]=8;
guo[193].name="江子焕";type[193]=136;
guo[194].name="金涛杰";type[194]=8;
guo[195].name="鲁毅涛";type[195]=536;
guo[196].name="鲁煜恺";type[196]=552;
guo[197].name="施熠辉";type[197]=8;
guo[198].name="宋世煜";type[198]=8;
guo[199].name="苏修远";type[199]=8;
guo[200].name="孙博波";type[200]=8;
guo[201].name="陶晨阳";type[201]=8;
guo[202].name="王彬  ";type[202]=8;
guo[203].name="王颖杰";type[203]=8;
guo[204].name="王宇龙";type[204]=536;
guo[205].name="吴涵  ";type[205]=8;
guo[206].name="夏泽楷";type[206]=8;
guo[207].name="谢泽栋";type[207]=8;
guo[208].name="袁晟轶";type[208]=72;
guo[209].name="张飞跃";type[209]=8;
guo[210].name="张泠璞";type[210]=136;
guo[211].name="周卓效";type[211]=136;
guo[212].name="朱力宇";type[212]=8;
guo[213].name="祝嘉君";type[213]=8;
guo[214].name="崔洲映";type[214]=16;
guo[215].name="刘美君";type[215]=16;
guo[216].name="娄珊珊";type[216]=16;
guo[217].name="楼嘉滢";type[217]=16;
guo[218].name="秦佳怡";type[218]=16;
guo[219].name="寿绮雯";type[219]=16;
guo[220].name="尉子仪";type[220]=16;
guo[221].name="杨可宜";type[221]=528;
guo[222].name="钟敏宜";type[222]=16;
guo[223].name="鲍睿阳";type[223]=528;
guo[224].name="冯周  ";type[224]=528;
guo[225].name="付诗昊";type[225]=528;
guo[226].name="胡哲昊";type[226]=16;
guo[227].name="蒋易杰";type[227]=16;
guo[228].name="李海东";type[228]=528;
guo[229].name="李睿城";type[229]=528;
guo[230].name="郦东昊";type[230]=528;
guo[231].name="潘祝君";type[231]=16;
guo[232].name="戚予立";type[232]=528;
guo[233].name="沈敏杰";type[233]=16;
guo[234].name="王安煜";type[234]=528;
guo[235].name="王杰涛";type[235]=528;
guo[236].name="夏翊哲";type[236]=528;
guo[237].name="许泽坤";type[237]=16;
guo[238].name="张逸群";type[238]=16;
guo[239].name="章俊杰";type[239]=16;
guo[240].name="诸咏涛";type[240]=528;
guo[241].name="金思远";type[241]=16;
guo[242].name="陈仕辰";type[242]=544;
guo[243].name="丁惠峰";type[243]=32;
guo[244].name="丁纳川";type[244]=32;
guo[245].name="蒋泽华";type[245]=32;
guo[246].name="杨臻超";type[246]=32;
guo[247].name="叶晗晓";type[247]=544;
guo[248].name="赵炫承";type[248]=32;
guo[249].name="鲍逸娴";type[249]=544;
guo[250].name="陈凯颖";type[250]=544;
guo[251].name="陈鸣赛";type[251]=32;
guo[252].name="陈诗楠";type[252]=544;
guo[253].name="丁颖  ";type[253]=544;
guo[254].name="杜依晗";type[254]=544;
guo[255].name="冯奕婷";type[255]=544;
guo[256].name="何彦仪";type[256]=544;
guo[257].name="洪佳莉";type[257]=544;
guo[258].name="蒋晓能";type[258]=32;
guo[259].name="金恬  ";type[259]=32;
guo[260].name="金一丹";type[260]=544;
guo[261].name="孔佳慧";type[261]=544;
guo[262].name="李佳宁";type[262]=544;
guo[263].name="刘钰沣";type[263]=32;
guo[264].name="潘婷婷";type[264]=544;
guo[265].name="祁雪丹";type[265]=32;
guo[266].name="阮嘉烨";type[266]=32;
guo[267].name="沈佳雯";type[267]=544;
guo[268].name="汤喻淇";type[268]=32;
guo[269].name="陶妍祺";type[269]=32;
guo[270].name="屠翌  ";type[270]=544;
guo[271].name="王烨  ";type[271]=32;
guo[272].name="吴皆宁";type[272]=544;
guo[273].name="夏文珏";type[273]=32;
guo[274].name="肖潇  ";type[274]=32;
guo[275].name="徐煜姣";type[275]=32;
guo[276].name="许颖莹";type[276]=32;
guo[277].name="尹嘉仪";type[277]=32;
guo[278].name="应佳熠";type[278]=32;
guo[279].name="詹潇潇";type[279]=32;
guo[280].name="张晓冉";type[280]=32;
guo[281].name="赵华琴";type[281]=32;
guo[282].name="钟佳琦";type[282]=32;
guo[283].name="周冰洁";type[283]=32;
guo[284].name="周伶滢";type[284]=32;
guo[285].name="周颖  ";type[285]=32;
guo[286].name="朱瑾  ";type[286]=32;
guo[287].name="祝涵瑜";type[287]=32;
guo[288].name="丁嘉浩";type[288]=64;
guo[289].name="韩求是";type[289]=64;
guo[290].name="李京  ";type[290]=64;
guo[291].name="缪源一";type[291]=64;
guo[292].name="钱庆来";type[292]=64;
guo[293].name="孙恩凯";type[293]=64;
guo[294].name="田哲男";type[294]=64;
guo[295].name="屠天航";type[295]=64;
guo[296].name="王昊石";type[296]=64;
guo[297].name="吴威特";type[297]=64;
guo[298].name="吴一舟";type[298]=64;
guo[299].name="杨奕帆";type[299]=64;
guo[300].name="诸迪洋";type[300]=64;
guo[301].name="陈丹  ";type[301]=64;
guo[302].name="陈威  ";type[302]=64;
guo[303].name="陈一鸣";type[303]=64;
guo[304].name="陈怡洁";type[304]=64;
guo[305].name="丁程阳";type[305]=64;
guo[306].name="丁伊娜";type[306]=64;
guo[307].name="傅佳雯";type[307]=64;
guo[308].name="郭羽晨";type[308]=64;
guo[309].name="胡乐怡";type[309]=64;
guo[310].name="胡宁泱";type[310]=64;
guo[311].name="金铭萱";type[311]=64;
guo[312].name="李雯  ";type[312]=64;
guo[313].name="林雪旖";type[313]=64;
guo[314].name="刘怡青";type[314]=64;
guo[315].name="鲁洁  ";type[315]=64;
guo[316].name="裘真  ";type[316]=64;
guo[317].name="沈佳楠";type[317]=64;
guo[318].name="史淑琦";type[318]=64;
guo[319].name="谭跃洲";type[319]=64;
guo[320].name="陶欣怡";type[320]=64;
guo[321].name="陶喆煊";type[321]=64;
guo[322].name="王佳熠";type[322]=64;
guo[323].name="王佩婧";type[323]=64;
guo[324].name="王雨妮";type[324]=64;
guo[325].name="沃睿萱";type[325]=64;
guo[326].name="夏青莲";type[326]=64;
guo[327].name="徐弘仪";type[327]=64;
guo[328].name="杨嘉敏";type[328]=64;
guo[329].name="余婕  ";type[329]=64;
guo[330].name="袁诗霞";type[330]=64;
guo[331].name="袁逸飞";type[331]=64;
guo[332].name="张加乔";type[332]=64;
guo[333].name="张逸静";type[333]=64;
guo[334].name="张玥  ";type[334]=64;
guo[335].name="章凯雯";type[335]=64;
guo[336].name="朱晓颖";type[336]=64;
guo[337].name="单松涛";type[337]=128;
guo[338].name="单子渐";type[338]=128;
guo[339].name="傅樟明";type[339]=128;
guo[340].name="楼晨  ";type[340]=128;
guo[341].name="祁丁涛";type[341]=128;
guo[342].name="寿倪正";type[342]=128;
guo[343].name="汪书楠";type[343]=128;
guo[344].name="王彦森";type[344]=128;
guo[345].name="尉宸浩";type[345]=128;
guo[346].name="周正昊";type[346]=128;
guo[347].name="鲍文清";type[347]=128;
guo[348].name="曹雨琦";type[348]=128;
guo[349].name="陈姝烨";type[349]=128;
guo[350].name="丁奕楠";type[350]=128;
guo[351].name="樊晓珂";type[351]=128;
guo[352].name="郭艺琳";type[352]=128;
guo[353].name="郭芷渝";type[353]=128;
guo[354].name="洪依婷";type[354]=128;
guo[355].name="胡琪琦";type[355]=128;
guo[356].name="李雨欣";type[356]=128;
guo[357].name="郦羽杰";type[357]=128;
guo[358].name="刘星芸";type[358]=128;
guo[359].name="罗卓亚";type[359]=128;
guo[360].name="马钟欣";type[360]=128;
guo[361].name="孟琴音";type[361]=128;
guo[362].name="孟烨珂";type[362]=128;
guo[363].name="孟子矜";type[363]=128;
guo[364].name="潘思懿";type[364]=128;
guo[365].name="潘雅婷";type[365]=128;
guo[366].name="潘桢妍";type[366]=128;
guo[367].name="庞亚轩";type[367]=128;
guo[368].name="阮赵可";type[368]=128;
guo[369].name="沈嘉怡";type[369]=128;
guo[370].name="沈姝曼";type[370]=128;
guo[371].name="王润叶";type[371]=128;
guo[372].name="王艺陶";type[372]=128;
guo[373].name="吴妤祺";type[373]=128;
guo[374].name="邢楚涵";type[374]=128;
guo[375].name="徐嘉璐";type[375]=128;
guo[376].name="徐乐浓";type[376]=128;
guo[377].name="徐小荃";type[377]=128;
guo[378].name="许飞扬";type[378]=128;
guo[379].name="余佳成";type[379]=128;
guo[380].name="袁晓霞";type[380]=128;
guo[381].name="陈方彬";type[381]=256;
guo[382].name="陈奕铭";type[382]=256;
guo[383].name="方博  ";type[383]=256;
guo[384].name="傅可树";type[384]=256;
guo[385].name="韩天任";type[385]=256;
guo[386].name="金之谦";type[386]=256;
guo[387].name="李企峥";type[387]=256;
guo[388].name="梁孜祺";type[388]=256;
guo[389].name="吕锦泽";type[389]=256;
guo[390].name="吕治衡";type[390]=256;
guo[391].name="罗江楠";type[391]=256;
guo[392].name="孟戴..";type[392]=256;
guo[393].name="沈哲贝";type[393]=256;
guo[394].name="宋冠儒";type[394]=256;
guo[395].name="王路  ";type[395]=256;
guo[396].name="吴泽涛";type[396]=256;
guo[397].name="章峥  ";type[397]=256;
guo[398].name="周栩航";type[398]=256;
guo[399].name="周雨扬";type[399]=256;
guo[400].name="朱铖昊";type[400]=256;
guo[401].name="刘柏成";type[401]=256;
guo[402].name="李益开";type[402]=512;
guo[403].name="吕柳城";type[403]=512;
guo[404].name="钱奕丞";type[404]=512;
guo[405].name="任奕遒";type[405]=512;
guo[406].name="王一择";type[406]=512;
guo[407].name="张世聪";type[407]=512;
guo[408].name="孟国焕";type[408]=1;
guo[409].name="章妃英";type[409]=2;
guo[410].name="丁素琴";type[410]=516;
guo[411].name="何凯  ";type[411]=8;
guo[412].name="陈丹燕";type[412]=16;
guo[413].name="傅芳芳";type[413]=32;
guo[414].name="沈剑蕾";type[414]=64;
guo[415].name="彭爱波";type[415]=128;
guo[416].name="韩小红";type[416]=512;
guo[417].name="陈锦涛";type[417]=512;
guo[418].name="陈奕然";type[418]=512;
guo[419].name="陈益扬";type[419]=512;
guo[420].name="鲁雨成";type[420]=512;
guo[421].name="顾家俊";type[421]=512;
guo[422].name="俞晨亮";type[422]=512;
guo[423].name="郑栋杰";type[423]=512;
guo[424].name="凌栋钦";type[424]=512;
guo[425].name="陈义兵（全能神！水土不服只服他）";type[425]=512;

for(int i=1;i<=cnt;i++)for(int j=i+1;j<=cnt;j++){
	tu[i][j]=tu[j][i]=rand()%90+10;
	//if(i<=2)tu[i][j]++,tu[j][i]++;
	if(type[i]&type[j]&511);
	else if((type[i]==512&&512==type[j]));
	else if(type[i]&type[j])tu[i][j]+=100,tu[j][i]+=100;
	else if((3&type[i])&&(3&type[j])||(12&type[i])&&(12&type[j])||(752&type[i])&&(752&type[j]))tu[i][j]+=200,tu[j][i]+=200;
	else if((1020&type[i])&&(1020&type[j]))tu[i][j]+=400,tu[j][i]+=400;
	else tu[i][j]+=1200,tu[j][i]+=1200;
}
for(i=1;i<=cnt;i++)guo[i]={guo[i].name,"",200,50,50,50,61,50,0,0};
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			sh[i]=0;du[i]=0;xz[i]=0;q[i]=0;bj[i]=i;xT[i]=0;gg[i]=0;si[i]=0;
			guo[i].tu=guo[i].name.length()<=4||guo[i].name[4]==' '?guo[i].name.substr(2,2):guo[i].name.substr(4,2);
			guo[i].tu+="土";
			if(i==29||i==32||i==33||i==34||i==42||i==45||i==49||i==53)guo[i].tu="妖土";
			if(i==1||i==2)guo[i].tu="  土";
			if(i==6||i==104||i==156)guo[i].tu="死土";
			if(i==14||i==67||i==37||i==52)guo[i].tu="猪土";
			if(i==15)guo[i].tu="狗土";
		}Y=2013;M=9;W=0;YY=0;MM=0;WW=1;
}
if(T==18){
	cnt=873;orz="同学";typ=0;ty=1;d1=20;d2=40;_=0;rev=1;fr[7][869]=fr[869][7]=1;
	int type[1024];
guo[1].name="敖以恒";type[1]=401;
guo[2].name="班越童";type[2]=1106;
guo[3].name="包菁菁";type[3]=509;
guo[4].name="包灵怡";type[4]=1009;
guo[5].name="包文涵";type[5]=1208;
guo[6].name="包逸昊";type[6]=203;
guo[7].name="鲍东方";type[7]=1009;
guo[8].name="鲍荣瑜";type[8]=414;
guo[9].name="鲍睿阳";type[9]=1011;
guo[10].name="鲍文清";type[10]=503;
guo[11].name="鲍易韬";type[11]=1203;
guo[12].name="鲍逸娴";type[12]=1402;
guo[13].name="蔡格非";type[13]=1515;
guo[14].name="蔡晶晶";type[14]=104;
guo[15].name="蔡元熠";type[15]=1202;
guo[16].name="曹成灿";type[16]=214;
guo[17].name="曹依宁";type[17]=113;
guo[18].name="曹雨琦";type[18]=502;
guo[19].name="曹周川";type[19]=306;
guo[20].name="岑明祥";type[20]=1107;
guo[21].name="柴宇栋";type[21]=710;
guo[22].name="柴雨诗";type[22]=1515;
guo[23].name="常琳";type[23]=108;
guo[24].name="车央菲";type[24]=1409;
guo[25].name="陈彬";type[25]=212;
guo[26].name="陈程帆";type[26]=206;
guo[27].name="陈聪";type[27]=913;
guo[28].name="陈丹";type[28]=606;
guo[29].name="陈公泱";type[29]=210;
guo[30].name="陈昊";type[30]=903;
guo[31].name="陈浩";type[31]=305;
guo[32].name="陈佳琰";type[32]=108;
guo[33].name="陈佳颖";type[33]=108;
guo[34].name="陈嘉豪";type[34]=305;
guo[35].name="陈江南";type[35]=800;
guo[36].name="陈锦涛";type[36]=1304;
guo[37].name="陈凯颖";type[37]=1402;
guo[38].name="陈立";type[38]=1314;
guo[39].name="陈龙翀";type[39]=1009;
guo[40].name="陈明洁";type[40]=102;
guo[41].name="陈鸣赛";type[41]=1404;
guo[42].name="陈诺";type[42]=1307;
guo[43].name="陈齐治";type[43]=1009;
guo[44].name="陈启楠";type[44]=209;
guo[45].name="陈沁怡";type[45]=705;
guo[46].name="陈沁芸";type[46]=303;
guo[47].name="陈青霞";type[47]=112;
guo[48].name="陈少楠";type[48]=904;
guo[49].name="陈诗楠";type[49]=1406;
guo[50].name="陈仕辰";type[50]=1404;
guo[51].name="陈姝烨";type[51]=502;
guo[52].name="陈思诺";type[52]=308;
guo[53].name="陈思源";type[53]=1104;
guo[54].name="陈天宇";type[54]=1105;
guo[55].name="陈威";type[55]=606;
guo[56].name="陈曦";type[56]=705;
guo[57].name="陈晓烨";type[57]=1203;
guo[58].name="陈晓玥";type[58]=401;
guo[59].name="陈欣雨";type[59]=1112;
guo[60].name="陈新";type[60]=1106;
guo[61].name="陈星悦";type[61]=910;
guo[62].name="陈幸媛";type[62]=1312;
guo[63].name="陈叶清";type[63]=1204;
guo[64].name="陈烨霏";type[64]=813;
guo[65].name="陈一鸣";type[65]=608;
guo[66].name="陈依娜";type[66]=1616;
guo[67].name="陈祎涵";type[67]=804;
guo[68].name="陈怡洁";type[68]=603;
guo[69].name="陈以非";type[69]=1515;
guo[70].name="陈奕然";type[70]=1304;
guo[71].name="陈益强";type[71]=310;
guo[72].name="陈益扬";type[72]=1301;
guo[73].name="陈颖超";type[73]=806;
guo[74].name="陈颖楠";type[74]=103;
guo[75].name="陈羽柯";type[75]=106;
guo[76].name="陈雨珂";type[76]=1301;
guo[77].name="陈泽浩";type[77]=910;
guo[78].name="陈震泽";type[78]=1202;
guo[79].name="陈之楷";type[79]=3;
guo[80].name="陈卓政";type[80]=1515;
guo[81].name="成倩汝";type[81]=401;
guo[82].name="程刚";type[82]=202;
guo[83].name="程杰";type[83]=705;
guo[84].name="程诺";type[84]=413;
guo[85].name="褚步霄";type[85]=1009;
guo[86].name="崔佳文";type[86]=1616;
guo[87].name="崔立添";type[87]=1515;
guo[88].name="崔洲映";type[88]=1003;
guo[89].name="戴立奇";type[89]=1100;
guo[90].name="戴世达";type[90]=810;
guo[91].name="单佳梦";type[91]=408;
guo[92].name="单松涛";type[92]=506;
guo[93].name="单王杰";type[93]=106;
guo[94].name="单雨恬";type[94]=1515;
guo[95].name="单昱呈";type[95]=904;
guo[96].name="单子渐";type[96]=505;
guo[97].name="邓仁杰";type[97]=709;
guo[98].name="邓宇鑫";type[98]=1208;
guo[99].name="丁博毅";type[99]=311;
guo[100].name="丁程阳";type[100]=611;
guo[101].name="丁惠峰";type[101]=1402;
guo[102].name="丁佳尔";type[102]=103;
guo[103].name="丁嘉浩";type[103]=603;
guo[104].name="丁纳川";type[104]=1406;
guo[105].name="丁纳海";type[105]=106;
guo[106].name="丁奇瑶";type[106]=509;
guo[107].name="丁阳";type[107]=310;
guo[108].name="丁伊娜";type[108]=605;
guo[109].name="丁奕楠";type[109]=513;
guo[110].name="丁颖";type[110]=1402;
guo[111].name="丁祝涛";type[111]=1106;
guo[112].name="董炬悦";type[112]=913;
guo[113].name="董天禹";type[113]=212;
guo[114].name="董恬恬";type[114]=814;
guo[115].name="董翔宇";type[115]=705;
guo[116].name="董雪珂";type[116]=804;
guo[117].name="董振皓";type[117]=1203;
guo[118].name="董之瑜";type[118]=813;
guo[119].name="杜晗晨";type[119]=914;
guo[120].name="杜天意";type[120]=1107;
guo[121].name="杜逍云";type[121]=1301;
guo[122].name="杜心怡";type[122]=1616;
guo[123].name="杜依";type[123]=210;
guo[124].name="杜依晗";type[124]=1405;
guo[125].name="樊豪成";type[125]=1616;
guo[126].name="樊任辉";type[126]=102;
guo[127].name="樊晓珂";type[127]=501;
guo[128].name="范丁晨";type[128]=1112;
guo[129].name="范文意";type[129]=807;
guo[130].name="方高峰";type[130]=710;
guo[131].name="方沁奕";type[131]=1304;
guo[132].name="方震";type[132]=1009;
guo[133].name="费喆";type[133]=1515;
guo[134].name="封岑琦";type[134]=112;
guo[135].name="封姚逸";type[135]=1616;
guo[136].name="封卓宁";type[136]=402;
guo[137].name="冯诚君";type[137]=1411;
guo[138].name="冯佳依";type[138]=805;
guo[139].name="冯可树";type[139]=204;
guo[140].name="冯沁悦";type[140]=707;
guo[141].name="冯天祺";type[141]=201;
guo[142].name="冯奕婷";type[142]=1407;
guo[143].name="冯滢";type[143]=711;
guo[144].name="冯宇飞";type[144]=1304;
guo[145].name="冯泽越";type[145]=1213;
guo[146].name="冯周";type[146]=1311;
guo[147].name="付晨阳";type[147]=313;
guo[148].name="付诗昊";type[148]=1011;
guo[149].name="傅佳雯";type[149]=605;
guo[150].name="傅杰郁阳";type[150]=905;
guo[151].name="傅君扬";type[151]=2;
guo[152].name="傅俊杰";type[152]=301;
guo[153].name="傅乐天";type[153]=1009;
guo[154].name="傅鹏宇";type[154]=1616;
guo[155].name="傅文杰";type[155]=107;
guo[156].name="傅雪艺";type[156]=914;
guo[157].name="傅烨雷";type[157]=812;
guo[158].name="傅依雯";type[158]=1009;
guo[159].name="傅咏烽";type[159]=206;
guo[160].name="傅雨涵";type[160]=1515;
guo[161].name="傅樟明";type[161]=508;
guo[162].name="干博";type[162]=310;
guo[163].name="高成";type[163]=1616;
guo[164].name="高胜男";type[164]=1413;
guo[165].name="高雅雯";type[165]=807;
guo[166].name="高宜骋";type[166]=112;
guo[167].name="高屹雯";type[167]=11;
guo[168].name="高瑜";type[168]=203;
guo[169].name="高源";type[169]=308;
guo[170].name="葛俏青";type[170]=807;
guo[171].name="葛欣媛";type[171]=1110;
guo[172].name="顾朝源";type[172]=302;
guo[173].name="顾家俊";type[173]=1304;
guo[174].name="顾依珂";type[174]=614;
guo[175].name="顾熠";type[175]=813;
guo[176].name="郭佳燕";type[176]=1201;
guo[177].name="郭楠";type[177]=1009;
guo[178].name="郭杨杰";type[178]=1616;
guo[179].name="郭艺琳";type[179]=501;
guo[180].name="郭羽晨";type[180]=603;
guo[181].name="郭芷渝";type[181]=506;
guo[182].name="韩慧瑜";type[182]=809;
guo[183].name="韩孟霖";type[183]=1616;
guo[184].name="韩启煊";type[184]=1205;
guo[185].name="韩求是";type[185]=603;
guo[186].name="韩一洲";type[186]=103;
guo[187].name="韩怡添";type[187]=413;
guo[188].name="何晨泽";type[188]=1009;
guo[189].name="何楚楚";type[189]=1414;
guo[190].name="何东彦";type[190]=405;
guo[191].name="何怀真";type[191]=411;
guo[192].name="何霁寒";type[192]=205;
guo[193].name="何家琦";type[193]=207;
guo[194].name="何恺昱";type[194]=408;
guo[195].name="何旻涵";type[195]=1210;
guo[196].name="何睿";type[196]=10;
guo[197].name="何赛飞";type[197]=813;
guo[198].name="何仕阳";type[198]=1515;
guo[199].name="何心仪";type[199]=109;
guo[200].name="何星仪";type[200]=1515;
guo[201].name="何雪雯";type[201]=1114;
guo[202].name="何彦仪";type[202]=1405;
guo[203].name="何晏清";type[203]=402;
guo[204].name="何烨超";type[204]=913;
guo[205].name="何怡鼎";type[205]=1104;
guo[206].name="何逸飞";type[206]=811;
guo[207].name="何越菲";type[207]=804;
guo[208].name="何志强";type[208]=1208;
guo[209].name="洪佳莉";type[209]=1412;
guo[210].name="洪珂凡";type[210]=514;
guo[211].name="洪依婷";type[211]=512;
guo[212].name="胡冰清";type[212]=406;
guo[213].name="胡城豪";type[213]=913;
guo[214].name="胡董阳";type[214]=911;
guo[215].name="胡寒昱";type[215]=1209;
guo[216].name="胡凯捷";type[216]=1013;
guo[217].name="胡楷其";type[217]=1515;
guo[218].name="胡乐怡";type[218]=613;
guo[219].name="胡琳妍";type[219]=1414;
guo[220].name="胡宁泱";type[220]=612;
guo[221].name="胡鹏飞";type[221]=103;
guo[222].name="胡琪琦";type[222]=513;
guo[223].name="胡乔桦";type[223]=911;
guo[224].name="胡杉";type[224]=1203;
guo[225].name="胡欣瑜";type[225]=1616;
guo[226].name="胡一涛";type[226]=1111;
guo[227].name="胡垠霞";type[227]=1204;
guo[228].name="胡颖";type[228]=1208;
guo[229].name="胡语涵";type[229]=416;
guo[230].name="胡蕴文";type[230]=102;
guo[231].name="胡哲昊";type[231]=1013;
guo[232].name="黄杭旗";type[232]=1212;
guo[233].name="黄浩瀚";type[233]=304;
guo[234].name="黄嘉宝";type[234]=1209;
guo[235].name="黄江英";type[235]=408;
guo[236].name="黄乐了";type[236]=1110;
guo[237].name="黄丽燕";type[237]=405;
guo[238].name="黄睿琳";type[238]=1314;
guo[239].name="黄勇";type[239]=214;
guo[240].name="黄雨楚";type[240]=107;
guo[241].name="惠雷";type[241]=207;
guo[242].name="纪冬颖";type[242]=911;
guo[243].name="季佳怡";type[243]=1515;
guo[244].name="季羽凝";type[244]=705;
guo[245].name="贾谷兰";type[245]=1304;
guo[246].name="江子焕";type[246]=514;
guo[247].name="蒋东昊";type[247]=912;
guo[248].name="蒋海斌";type[248]=201;
guo[249].name="蒋鸿程";type[249]=1207;
guo[250].name="蒋思瑜";type[250]=112;
guo[251].name="蒋王英";type[251]=1307;
guo[252].name="蒋晓能";type[252]=1411;
guo[253].name="蒋易杰";type[253]=1013;
guo[254].name="蒋泽华";type[254]=1413;
guo[255].name="蒋志锴";type[255]=911;
guo[256].name="蒋卓颖";type[256]=1616;
guo[257].name="金驰凯";type[257]=11;
guo[258].name="金典";type[258]=1515;
guo[259].name="金观能";type[259]=700;
guo[260].name="金佳萍";type[260]=904;
guo[261].name="金洁";type[261]=311;
guo[262].name="金璟";type[262]=203;
guo[263].name="金灵锋";type[263]=402;
guo[264].name="金灵旷怡";type[264]=12;
guo[265].name="金铭萱";type[265]=613;
guo[266].name="金能";type[266]=8;
guo[267].name="金诗雨";type[267]=2;
guo[268].name="金思远";type[268]=1008;
guo[269].name="金涛杰";type[269]=214;
guo[270].name="金天宇";type[270]=9;
guo[271].name="金恬";type[271]=412;
guo[272].name="金庭冉";type[272]=409;
guo[273].name="金薇薇";type[273]=407;
guo[274].name="金骁杨";type[274]=1207;
guo[275].name="金妍池";type[275]=1311;
guo[276].name="金颜童";type[276]=401;
guo[277].name="金一丹";type[277]=1410;
guo[278].name="金易文";type[278]=1515;
guo[279].name="金轶嘉";type[279]=108;
guo[280].name="金逸宁";type[280]=803;
guo[281].name="金垠锜";type[281]=904;
guo[282].name="金英杰";type[282]=210;
guo[283].name="金宇杰";type[283]=1207;
guo[284].name="金雨丰";type[284]=1616;
guo[285].name="金雨卡";type[285]=413;
guo[286].name="金玉婷";type[286]=1312;
guo[287].name="金裕杰";type[287]=1515;
guo[288].name="金峥";type[288]=108;
guo[289].name="金政扬";type[289]=1203;
guo[290].name="晋诗羽";type[290]=1304;
guo[291].name="靳炜杰";type[291]=813;
guo[292].name="孔佳慧";type[292]=1407;
guo[293].name="劳心仪";type[293]=408;
guo[294].name="李超奇";type[294]=705;
guo[295].name="李海东";type[295]=1012;
guo[296].name="李豪森";type[296]=310;
guo[297].name="李浩腾";type[297]=705;
guo[298].name="李佳宁";type[298]=1402;
guo[299].name="李家成";type[299]=1009;
guo[300].name="李京";type[300]=606;
guo[301].name="李旼晖";type[301]=206;
guo[302].name="李睿";type[302]=402;
guo[303].name="李睿城";type[303]=1011;
guo[304].name="李若男";type[304]=705;
guo[305].name="李恬儿";type[305]=806;
guo[306].name="李想";type[306]=1515;
guo[307].name="李笑笑";type[307]=606;
guo[308].name="李轩昊";type[308]=701;
guo[309].name="李益开";type[309]=1105;
guo[310].name="李宇楠";type[310]=208;
guo[311].name="李雨桐";type[311]=810;
guo[312].name="李雨欣";type[312]=501;
guo[313].name="李浙湘";type[313]=114;
guo[314].name="李卓霖";type[314]=410;
guo[315].name="厉文浩";type[315]=1310;
guo[316].name="郦东昊";type[316]=1311;
guo[317].name="郦羽杰";type[317]=507;
guo[318].name="郦秩";type[318]=1306;
guo[319].name="林佳倩";type[319]=904;
guo[320].name="林雪旖";type[320]=612;
guo[321].name="林质彬";type[321]=1102;
guo[322].name="凌栋钦";type[322]=1306;
guo[323].name="凌佳欣";type[323]=405;
guo[324].name="刘佳其";type[324]=1110;
guo[325].name="刘美君";type[325]=1006;
guo[326].name="刘星芸";type[326]=513;
guo[327].name="刘依兰";type[327]=112;
guo[328].name="刘怡青";type[328]=605;
guo[329].name="刘钰沣";type[329]=1405;
guo[330].name="柳嘉仪";type[330]=1307;
guo[331].name="娄珊珊";type[331]=1007;
guo[332].name="娄世绎";type[332]=1411;
guo[333].name="娄天一";type[333]=1210;
guo[334].name="娄一凡";type[334]=1616;
guo[335].name="楼晨";type[335]=505;
guo[336].name="楼家宁";type[336]=809;
guo[337].name="楼嘉滢";type[337]=506;
guo[338].name="卢易伽";type[338]=1204;
guo[339].name="鲁佳城";type[339]=902;
guo[340].name="鲁洁";type[340]=606;
guo[341].name="鲁炆杰";type[341]=903;
guo[342].name="鲁耀威";type[342]=212;
guo[343].name="鲁一晨";type[343]=706;
guo[344].name="鲁意";type[344]=109;
guo[345].name="鲁毅涛";type[345]=1314;
guo[346].name="鲁雨成";type[346]=1312;
guo[347].name="鲁煜恺";type[347]=1414;
guo[348].name="陆涵颖";type[348]=401;
guo[349].name="陆浩天";type[349]=1313;
guo[350].name="陆宇杰";type[350]=902;
guo[351].name="路孝萌";type[351]=1212;
guo[352].name="栾俊宁";type[352]=801;
guo[353].name="罗晨浩";type[353]=703;
guo[354].name="罗江涛";type[354]=904;
guo[355].name="罗凯楠";type[355]=704;
guo[356].name="罗可典";type[356]=705;
guo[357].name="罗文颀";type[357]=1616;
guo[358].name="罗卓亚";type[358]=507;
guo[359].name="吕康杰";type[359]=303;
guo[360].name="吕柳城";type[360]=108;
guo[361].name="吕润泽";type[361]=908;
guo[362].name="吕晓筱";type[362]=1301;
guo[363].name="吕中宁";type[363]=1616;
guo[364].name="马丹阳";type[364]=904;
guo[365].name="马宁敏";type[365]=702;
guo[366].name="马琦梦";type[366]=110;
guo[367].name="马书立";type[367]=1105;
guo[368].name="马田瑜";type[368]=1515;
guo[369].name="马钟欣";type[369]=504;
guo[370].name="马朱奕";type[370]=102;
guo[371].name="毛伊颜";type[371]=702;
guo[372].name="孟嘉政";type[372]=1212;
guo[373].name="孟琴音";type[373]=502;
guo[374].name="孟烨珂";type[374]=501;
guo[375].name="孟逸群";type[375]=712;
guo[376].name="孟子衿";type[376]=502;
guo[377].name="苗俊丰";type[377]=711;
guo[378].name="缪源一";type[378]=607;
guo[379].name="缪之恺";type[379]=1515;
guo[380].name="牟思涵";type[380]=1616;
guo[381].name="倪海森";type[381]=1515;
guo[382].name="倪晗悦";type[382]=1515;
guo[383].name="倪绮霞";type[383]=104;
guo[384].name="倪奕飞";type[384]=408;
guo[385].name="潘李靓";type[385]=410;
guo[386].name="潘林越";type[386]=1515;
guo[387].name="潘思懿";type[387]=505;
guo[388].name="潘婷婷";type[388]=1406;
guo[389].name="潘雅婷";type[389]=504;
guo[390].name="潘瑶婷";type[390]=406;
guo[391].name="潘雨婷";type[391]=905;
guo[392].name="潘桢妍";type[392]=510;
guo[393].name="潘祝君";type[393]=1010;
guo[394].name="庞琳杰";type[394]=1302;
guo[395].name="庞亚轩";type[395]=506;
guo[396].name="彭荣丽";type[396]=1204;
guo[397].name="平晨昊";type[397]=308;
guo[398].name="平幸卉";type[398]=112;
guo[399].name="戚天怡";type[399]=711;
guo[400].name="戚予立";type[400]=1003;
guo[401].name="祁丁涛";type[401]=510;
guo[402].name="祁浩";type[402]=711;
guo[403].name="祁开祺";type[403]=903;
guo[404].name="祁雪丹";type[404]=1410;
guo[405].name="钱晨炼";type[405]=1100;
guo[406].name="钱家瑜";type[406]=207;
guo[407].name="钱庆来";type[407]=602;
guo[408].name="钱胜男";type[408]=1114;
guo[409].name="钱书仰";type[409]=1616;
guo[410].name="钱奕丞";type[410]=107;
guo[411].name="秦佳怡";type[411]=1011;
guo[412].name="邱庆豪";type[412]=1201;
guo[413].name="邱仕豪";type[413]=106;
guo[414].name="裘剑飞";type[414]=904;
guo[415].name="裘思远";type[415]=514;
guo[416].name="裘天绮";type[416]=401;
guo[417].name="裘哲";type[417]=907;
guo[418].name="裘真";type[418]=611;
guo[419].name="裘峥";type[419]=1110;
guo[420].name="任皓炜";type[420]=206;
guo[421].name="任和";type[421]=1309;
guo[422].name="任君彬";type[422]=301;
guo[423].name="任奕遒";type[423]=106;
guo[424].name="任哲文";type[424]=1112;
guo[425].name="戎辉";type[425]=902;
guo[426].name="阮嘉烨";type[426]=1404;
guo[427].name="阮丽艳";type[427]=1202;
guo[428].name="阮敏捷";type[428]=710;
guo[429].name="阮文锋";type[429]=207;
guo[430].name="阮赵可";type[430]=506;
guo[431].name="商浚哲";type[431]=1207;
guo[432].name="商书畅";type[432]=901;
guo[433].name="邵丹菲";type[433]=1201;
guo[434].name="邵无为";type[434]=1311;
guo[435].name="沈晨阳";type[435]=1302;
guo[436].name="沈贺蕾";type[436]=509;
guo[437].name="沈佳楠";type[437]=603;
guo[438].name="沈佳雯";type[438]=1411;
guo[439].name="沈嘉怡";type[439]=503;
guo[440].name="沈静怡";type[440]=114;
guo[441].name="沈浚哲";type[441]=1303;
guo[442].name="沈敏杰";type[442]=1010;
guo[443].name="沈秦越";type[443]=15;
guo[444].name="沈姝曼";type[444]=503;
guo[445].name="沈淑怡";type[445]=407;
guo[446].name="沈雯怡";type[446]=1409;
guo[447].name="沈欣琪";type[447]=411;
guo[448].name="沈序戎";type[448]=1009;
guo[449].name="沈怡然";type[449]=7;
guo[450].name="沈奕楠";type[450]=813;
guo[451].name="沈溢鼎";type[451]=311;
guo[452].name="沈熠";type[452]=509;
guo[453].name="沈宇昊";type[453]=408;
guo[454].name="沈卓琼";type[454]=1616;
guo[455].name="施钦阗";type[455]=406;
guo[456].name="施熠辉";type[456]=1214;
guo[457].name="施征宇";type[457]=1616;
guo[458].name="石沁";type[458]=514;
guo[459].name="石震巍";type[459]=1616;
guo[460].name="史淑琦";type[460]=605;
guo[461].name="史永浩";type[461]=702;
guo[462].name="寿家跃";type[462]=1009;
guo[463].name="寿倪正";type[463]=506;
guo[464].name="寿绮雯";type[464]=1404;
guo[465].name="寿霆丰";type[465]=1107;
guo[466].name="寿洋洋";type[466]=812;
guo[467].name="寿之星";type[467]=1213;
guo[468].name="水丹枫";type[468]=609;
guo[469].name="水洋栋";type[469]=705;
guo[470].name="宋晨";type[470]=1616;
guo[471].name="宋嘉怡";type[471]=1515;
guo[472].name="宋婕";type[472]=1103;
guo[473].name="宋璟涵";type[473]=810;
guo[474].name="宋开程";type[474]=1616;
guo[475].name="宋琦";type[475]=1411;
guo[476].name="宋清哲";type[476]=311;
guo[477].name="宋沙清";type[477]=1207;
guo[478].name="宋世煜";type[478]=1214;
guo[479].name="宋雯睿";type[479]=514;
guo[480].name="宋妤恬";type[480]=614;
guo[481].name="宋芷盈";type[481]=1515;
guo[482].name="苏鹏涛";type[482]=1104;
guo[483].name="苏修远";type[483]=1114;
guo[484].name="孙博波";type[484]=814;
guo[485].name="孙丹娜";type[485]=1313;
guo[486].name="孙丁宜";type[486]=803;
guo[487].name="孙恩凯";type[487]=612;
guo[488].name="孙飞扬";type[488]=301;
guo[489].name="孙军耀";type[489]=1201;
guo[490].name="孙宁睿";type[490]=12;
guo[491].name="孙麒婷";type[491]=1301;
guo[492].name="孙乾程";type[492]=1600;
guo[493].name="孙洋";type[493]=211;
guo[494].name="孙以然";type[494]=212;
guo[495].name="孙宇晴";type[495]=1205;
guo[496].name="孙正男";type[496]=901;
guo[497].name="孙卓怡";type[497]=903;
guo[498].name="谭跃洲";type[498]=608;
guo[499].name="汤世俊";type[499]=301;
guo[500].name="汤喻淇";type[500]=1403;
guo[501].name="唐钰莹";type[501]=108;
guo[502].name="陶晨阳";type[502]=314;
guo[503].name="陶晨耀";type[503]=413;
guo[504].name="陶金奇";type[504]=1515;
guo[505].name="陶婷婷";type[505]=814;
guo[506].name="陶忻妤";type[506]=209;
guo[507].name="陶欣怡";type[507]=611;
guo[508].name="陶馨瑜";type[508]=407;
guo[509].name="陶妍祺";type[509]=1405;
guo[510].name="陶叶雨";type[510]=514;
guo[511].name="陶逸婷";type[511]=813;
guo[512].name="陶喆煊";type[512]=605;
guo[513].name="陶中天";type[513]=1515;
guo[514].name="滕铱珂";type[514]=1616;
guo[515].name="田婧";type[515]=1616;
guo[516].name="田哲男";type[516]=611;
guo[517].name="田振楠";type[517]=1009;
guo[518].name="童均浩";type[518]=910;
guo[519].name="童开翼";type[519]=407;
guo[520].name="童烁岚";type[520]=207;
guo[521].name="屠磊";type[521]=204;
guo[522].name="屠蕊林";type[522]=813;
guo[523].name="屠澍田";type[523]=1616;
guo[524].name="屠天波";type[524]=1515;
guo[525].name="屠天航";type[525]=601;
guo[526].name="屠翌";type[526]=1411;
guo[527].name="汪书楠";type[527]=501;
guo[528].name="汪垚程";type[528]=1310;
guo[529].name="王安煜";type[529]=1001;
guo[530].name="王彬";type[530]=214;
guo[531].name="王斌杰";type[531]=1104;
guo[532].name="王辰昊";type[532]=303;
guo[533].name="王含冰";type[533]=102;
guo[534].name="王韩杰";type[534]=1616;
guo[535].name="王昊石";type[535]=603;
guo[536].name="王浩宇";type[536]=1515;
guo[537].name="王赫铭";type[537]=813;
guo[538].name="王鸿宇";type[538]=303;
guo[539].name="王华磊";type[539]=105;
guo[540].name="王济源";type[540]=404;
guo[541].name="王佳丽";type[541]=101;
guo[542].name="王佳沁";type[542]=801;
guo[543].name="王佳熠";type[543]=606;
guo[544].name="王嘉豪";type[544]=802;
guo[545].name="王杰涛";type[545]=1004;
guo[546].name="王俊昊";type[546]=1210;
guo[547].name="王恺雨";type[547]=1502;
guo[548].name="王柯亭";type[548]=705;
guo[549].name="王可";type[549]=1515;
guo[550].name="王立凡";type[550]=805;
guo[551].name="王亮捷";type[551]=1616;
guo[552].name="王林龙";type[552]=412;
guo[553].name="王勉";type[553]=802;
guo[554].name="王佩婧";type[554]=612;
guo[555].name="王萍";type[555]=210;
guo[556].name="王奇燕";type[556]=111;
guo[557].name="王琦";type[557]=405;
guo[558].name="王青怡";type[558]=1515;
guo[559].name="王润叶";type[559]=501;
guo[560].name="王沈烨";type[560]=304;
guo[561].name="王司豪";type[561]=1605;
guo[562].name="王思妍";type[562]=1214;
guo[563].name="王天乐";type[563]=1009;
guo[564].name="王天耀";type[564]=705;
guo[565].name="王晓亮";type[565]=1307;
guo[566].name="王晓哲";type[566]=1515;
guo[567].name="王馨露";type[567]=807;
guo[568].name="王轩宇";type[568]=1109;
guo[569].name="王彦森";type[569]=504;
guo[570].name="王烨";type[570]=1401;
guo[571].name="王一择";type[571]=1107;
guo[572].name="王怡能";type[572]=1306;
guo[573].name="王弋戈";type[573]=1103;
guo[574].name="王亿铮";type[574]=211;
guo[575].name="王艺陶";type[575]=502;
guo[576].name="王毅扬";type[576]=13;
guo[577].name="王懿诺";type[577]=1515;
guo[578].name="王颖杰";type[578]=1114;
guo[579].name="王优";type[579]=1203;
guo[580].name="王余同";type[580]=308;
guo[581].name="王宇";type[581]=1616;
guo[582].name="王宇杰";type[582]=1312;
guo[583].name="王宇龙";type[583]=1014;
guo[584].name="王宇烜";type[584]=1307;
guo[585].name="王雨辰";type[585]=1109;
guo[586].name="王雨妮";type[586]=603;
guo[587].name="王雨萱";type[587]=1213;
guo[588].name="王渊龙";type[588]=1108;
guo[589].name="王泽城";type[589]=1515;
guo[590].name="王哲";type[590]=705;
guo[591].name="王政韬";type[591]=1113;
guo[592].name="王卓炜";type[592]=1112;
guo[593].name="王子习";type[593]=1009;
guo[594].name="王子越";type[594]=3;
guo[595].name="危方梦洁";type[595]=707;
guo[596].name="韦澳蕾";type[596]=1204;
guo[597].name="尉宸浩";type[597]=511;
guo[598].name="尉怡婷";type[598]=1210;
guo[599].name="尉子仪";type[599]=1004;
guo[600].name="魏一磊";type[600]=1616;
guo[601].name="翁凌洁";type[601]=801;
guo[602].name="沃睿萱";type[602]=604;
guo[603].name="邬依莉";type[603]=801;
guo[604].name="吴晨光";type[604]=1616;
guo[605].name="吴迪文";type[605]=401;
guo[606].name="吴丰威";type[606]=100;
guo[607].name="吴函咨";type[607]=803;
guo[608].name="吴涵";type[608]=1114;
guo[609].name="吴瀚琦";type[609]=707;
guo[610].name="吴红婕";type[610]=102;
guo[611].name="吴佳楠";type[611]=710;
guo[612].name="吴皆宁";type[612]=1401;
guo[613].name="吴津琪";type[613]=904;
guo[614].name="吴俊毅";type[614]=1103;
guo[615].name="吴旻";type[615]=1616;
guo[616].name="吴苏颖";type[616]=110;
guo[617].name="吴威特";type[617]=602;
guo[618].name="吴昕仪";type[618]=804;
guo[619].name="吴烨超";type[619]=107;
guo[620].name="吴一舟";type[620]=602;
guo[621].name="吴妤祺";type[621]=501;
guo[622].name="吴泽棋";type[622]=709;
guo[623].name="夏家乐";type[623]=207;
guo[624].name="夏敏茜";type[624]=1212;
guo[625].name="夏青莲";type[625]=608;
guo[626].name="夏文珏";type[626]=1005;
guo[627].name="夏翊哲";type[627]=1003;
guo[628].name="夏泽楷";type[628]=314;
guo[629].name="相佳玥";type[629]=1303;
guo[630].name="相卓伟";type[630]=1313;
guo[631].name="肖潇";type[631]=1413;
guo[632].name="肖洋溢";type[632]=1108;
guo[633].name="肖宇煊";type[633]=1515;
guo[634].name="谢超杰";type[634]=708;
guo[635].name="谢汉寅";type[635]=1201;
guo[636].name="谢鸿涛";type[636]=308;
guo[637].name="谢乐其";type[637]=1616;
guo[638].name="谢少杰";type[638]=100;
guo[639].name="谢世莹";type[639]=209;
guo[640].name="谢舒阳";type[640]=204;
guo[641].name="谢叶婷";type[641]=110;
guo[642].name="谢燚莹";type[642]=1614;
guo[643].name="谢雨桐";type[643]=1212;
guo[644].name="谢泽栋";type[644]=914;
guo[645].name="邢楚涵";type[645]=513;
guo[646].name="熊昊泉";type[646]=411;
guo[647].name="徐登科";type[647]=302;
guo[648].name="徐栋豪";type[648]=210;
guo[649].name="徐晗墨";type[649]=307;
guo[650].name="徐涵纯";type[650]=1211;
guo[651].name="徐浩然";type[651]=300;
guo[652].name="徐和杰";type[652]=712;
guo[653].name="徐弘仪";type[653]=605;
guo[654].name="徐佳浩";type[654]=308;
guo[655].name="徐佳薇";type[655]=712;
guo[656].name="徐家洛";type[656]=206;
guo[657].name="徐嘉婕";type[657]=810;
guo[658].name="徐嘉璐";type[658]=503;
guo[659].name="徐柯洋";type[659]=711;
guo[660].name="徐科宇";type[660]=1616;
guo[661].name="徐乐浓";type[661]=508;
guo[662].name="徐倩雯";type[662]=1201;
guo[663].name="徐如鸿";type[663]=513;
guo[664].name="徐童瑶";type[664]=114;
guo[665].name="徐希彦";type[665]=1009;
guo[666].name="徐潇彤";type[666]=1616;
guo[667].name="徐小荃";type[667]=508;
guo[668].name="徐怡";type[668]=908;
guo[669].name="徐旖旎";type[669]=405;
guo[670].name="徐意然";type[670]=1607;
guo[671].name="徐宇璐";type[671]=111;
guo[672].name="徐玉娇";type[672]=411;
guo[673].name="徐煜姣";type[673]=1405;
guo[674].name="徐悦";type[674]=808;
guo[675].name="徐泽男";type[675]=703;
guo[676].name="徐哲淇";type[676]=805;
guo[677].name="许飞扬";type[677]=513;
guo[678].name="许佳烨";type[678]=1313;
guo[679].name="许可沁";type[679]=211;
guo[680].name="许铭洋";type[680]=710;
guo[681].name="许诺";type[681]=402;
guo[682].name="许倩怡";type[682]=710;
guo[683].name="许书洋";type[683]=903;
guo[684].name="许亦雯";type[684]=408;
guo[685].name="许颖莹";type[685]=1406;
guo[686].name="许雨冰";type[686]=1210;
guo[687].name="许雨婷";type[687]=1515;
guo[688].name="许泽坤";type[688]=1012;
guo[689].name="宣晓洁";type[689]=108;
guo[690].name="薛鸽";type[690]=309;
guo[691].name="严嘉程";type[691]=704;
guo[692].name="严聚卫";type[692]=1313;
guo[693].name="严至简";type[693]=1616;
guo[694].name="阳宽心";type[694]=807;
guo[695].name="阳绍龙";type[695]=902;
guo[696].name="杨辰霄";type[696]=701;
guo[697].name="杨红帆";type[697]=901;
guo[698].name="杨嘉敏";type[698]=610;
guo[699].name="杨恺";type[699]=3;
guo[700].name="杨可宜";type[700]=1012;
guo[701].name="杨千仪";type[701]=6;
guo[702].name="杨熊涛";type[702]=808;
guo[703].name="杨许靖";type[703]=706;
guo[704].name="杨嫣然";type[704]=1113;
guo[705].name="杨以恒";type[705]=803;
guo[706].name="杨怿驰";type[706]=904;
guo[707].name="杨奕帆";type[707]=603;
guo[708].name="杨羽琪";type[708]=409;
guo[709].name="杨臻超";type[709]=1405;
guo[710].name="姚嘉程";type[710]=1014;
guo[711].name="姚洁";type[711]=1616;
guo[712].name="姚一旸";type[712]=303;
guo[713].name="叶冬";type[713]=708;
guo[714].name="叶晗晓";type[714]=1411;
guo[715].name="叶鸿飞";type[715]=702;
guo[716].name="叶灵";type[716]=1310;
guo[717].name="叶沁怡";type[717]=403;
guo[718].name="叶甜";type[718]=104;
guo[719].name="叶铮铮";type[719]=901;
guo[720].name="殷晗放";type[720]=1114;
guo[721].name="尹嘉仪";type[721]=1406;
guo[722].name="尹麒惠";type[722]=14;
guo[723].name="尹诗怡";type[723]=810;
guo[724].name="应佳熠";type[724]=1412;
guo[725].name="应筱菁";type[725]=101;
guo[726].name="应最时";type[726]=713;
guo[727].name="余晨阳";type[727]=1301;
guo[728].name="余红陆";type[728]=1112;
guo[729].name="余佳成";type[729]=507;
guo[730].name="余婕";type[730]=610;
guo[731].name="余舒阳";type[731]=911;
guo[732].name="余喆";type[732]=905;
guo[733].name="余子路";type[733]=1308;
guo[734].name="俞晨亮";type[734]=1308;
guo[735].name="俞飞菲";type[735]=102;
guo[736].name="俞浩楠";type[736]=208;
guo[737].name="俞鸿飞";type[737]=1009;
guo[738].name="俞景行";type[738]=1201;
guo[739].name="俞俊杰";type[739]=707;
guo[740].name="俞快";type[740]=909;
guo[741].name="俞梁";type[741]=912;
guo[742].name="俞林";type[742]=1313;
guo[743].name="俞婷";type[743]=111;
guo[744].name="俞杨";type[744]=1302;
guo[745].name="俞轶宸";type[745]=1307;
guo[746].name="俞逸凡";type[746]=609;
guo[747].name="虞快";type[747]=1009;
guo[748].name="喻天赐";type[748]=1515;
guo[749].name="袁佳菲";type[749]=214;
guo[750].name="袁晟轶";type[750]=614;
guo[751].name="袁诗霞";type[751]=604;
guo[752].name="袁晓霞";type[752]=501;
guo[753].name="袁益瑜";type[753]=614;
guo[754].name="袁逸飞";type[754]=607;
guo[755].name="詹潇潇";type[755]=713;
guo[756].name="詹致豪";type[756]=1309;
guo[757].name="张楚林";type[757]=908;
guo[758].name="张春雨";type[758]=301;
guo[759].name="张飞跃";type[759]=814;
guo[760].name="张傅斌";type[760]=202;
guo[761].name="张昊城";type[761]=1515;
guo[762].name="张浩渺";type[762]=304;
guo[763].name="张加乔";type[763]=613;
guo[764].name="张嘉琦";type[764]=1414;
guo[765].name="张杰";type[765]=905;
guo[766].name="张居正";type[766]=913;
guo[767].name="张凯程";type[767]=1107;
guo[768].name="张乐行";type[768]=1009;
guo[769].name="张琳洁";type[769]=308;
guo[770].name="张泠璞";type[770]=514;
guo[771].name="张刘灯";type[771]=1515;
guo[772].name="张美玲";type[772]=406;
guo[773].name="张米琪";type[773]=108;
guo[774].name="张楠";type[774]=1301;
guo[775].name="张世聪";type[775]=1106;
guo[776].name="张文杰";type[776]=1505;
guo[777].name="张晓冉";type[777]=1408;
guo[778].name="张欣泽";type[778]=1201;
guo[779].name="张杨含笑";type[779]=912;
guo[780].name="张一弛";type[780]=405;
guo[781].name="张怡婷";type[781]=1006;
guo[782].name="张旖雯";type[782]=405;
guo[783].name="张译丹";type[783]=1308;
guo[784].name="张羿";type[784]=11;
guo[785].name="张逸凡";type[785]=1009;
guo[786].name="张逸静";type[786]=613;
guo[787].name="张逸群";type[787]=1013;
guo[788].name="张逸涛";type[788]=609;
guo[789].name="张滢";type[789]=1209;
guo[790].name="张于晨";type[790]=1616;
guo[791].name="张与时";type[791]=811;
guo[792].name="张宇柠";type[792]=1616;
guo[793].name="张羽廷";type[793]=1515;
guo[794].name="张雨萌";type[794]=805;
guo[795].name="张雨倩";type[795]=114;
guo[796].name="张雨婷";type[796]=312;
guo[797].name="张玥";type[797]=610;
guo[798].name="张泽煜";type[798]=206;
guo[799].name="张政";type[799]=206;
guo[800].name="张洲";type[800]=1515;
guo[801].name="张竹青";type[801]=402;
guo[802].name="章嘉祺";type[802]=707;
guo[803].name="章俊杰";type[803]=411;
guo[804].name="章凯雯";type[804]=606;
guo[805].name="章梁";type[805]=1210;
guo[806].name="章彤彤";type[806]=1110;
guo[807].name="章一鸣";type[807]=1616;
guo[808].name="章一庄";type[808]=603;
guo[809].name="章雨静";type[809]=1515;
guo[810].name="赵晨含";type[810]=903;
guo[811].name="赵晨涛";type[811]=212;
guo[812].name="赵华琴";type[812]=1406;
guo[813].name="赵佳龙";type[813]=106;
guo[814].name="赵乐毅";type[814]=1009;
guo[815].name="赵楠";type[815]=1207;
guo[816].name="赵翔宇";type[816]=812;
guo[817].name="赵潇阳";type[817]=1112;
guo[818].name="赵炫承";type[818]=1406;
guo[819].name="赵逸凡";type[819]=410;
guo[820].name="赵煜文";type[820]=1207;
guo[821].name="赵元德";type[821]=1515;
guo[822].name="郑栋杰";type[822]=1301;
guo[823].name="郑楠";type[823]=812;
guo[824].name="郑艺航";type[824]=1112;
guo[825].name="郑子焓";type[825]=1616;
guo[826].name="钟佳琦";type[826]=1407;
guo[827].name="钟璟";type[827]=910;
guo[828].name="钟林昊";type[828]=302;
guo[829].name="钟敏宜";type[829]=1411;
guo[830].name="钟茜";type[830]=1616;
guo[831].name="钟诗颖";type[831]=202;
guo[832].name="钟一韬";type[832]=1616;
guo[833].name="钟奕楠";type[833]=1616;
guo[834].name="周冰洁";type[834]=1407;
guo[835].name="周陈滢";type[835]=903;
guo[836].name="周程扬";type[836]=1009;
guo[837].name="周傅毅楠";type[837]=913;
guo[838].name="周寒悦";type[838]=1302;
guo[839].name="周锦辉";type[839]=1208;
guo[840].name="周伶滢";type[840]=1408;
guo[841].name="周笑天";type[841]=1113;
guo[842].name="周一丹";type[842]=710;
guo[843].name="周颖";type[843]=1411;
guo[844].name="周宇辰";type[844]=1502;
guo[845].name="周宇婷";type[845]=614;
guo[846].name="周雨帆";type[846]=713;
guo[847].name="周泽浩";type[847]=311;
guo[848].name="周展逸";type[848]=1515;
guo[849].name="周正昊";type[849]=504;
guo[850].name="周正源";type[850]=1106;
guo[851].name="周郅杰";type[851]=1515;
guo[852].name="周卓效";type[852]=514;
guo[853].name="朱佳敏";type[853]=712;
guo[854].name="朱瑾";type[854]=1406;
guo[855].name="朱力宇";type[855]=1314;
guo[856].name="朱晓颖";type[856]=606;
guo[857].name="朱欣怡";type[857]=1302;
guo[858].name="朱幸晨";type[858]=702;
guo[859].name="朱仲达";type[859]=308;
guo[860].name="朱洲明";type[860]=909;
guo[861].name="诸迪洋";type[861]=601;
guo[862].name="诸梦琴";type[862]=1414;
guo[863].name="诸思湉";type[863]=812;
guo[864].name="诸咏涛";type[864]=213;
guo[865].name="竹韵";type[865]=911;
guo[866].name="祝涵瑜";type[866]=1412;
guo[867].name="祝嘉君";type[867]=714;
guo[868].name="祝晓斌";type[868]=1515;
guo[869].name="祝欣妍（猪妖为什么这么强）";type[869]=409;
guo[870].name="祝元仪";type[870]=909;
guo[871].name="祝元泽";type[871]=509;
guo[872].name="邹婕";type[872]=1404;
guo[873].name="邹雁杭";type[873]=705;

for(int i=1;i<=cnt;i++)for(int j=i+1;j<=cnt;j++){
	tu[i][j]=tu[j][i]=rand()%90+210;
	if(type[i]/100==type[j]/100&&type[i]/100>0)tu[i][j]=tu[j][i]=min(tu[i][j],rand()%90+10);
	if(type[i]%100==type[j]%100&&type[i]%100>0)tu[i][j]=tu[j][i]=min(tu[i][j],rand()%90+10);
}
for(i=1;i<=cnt;i++)guo[i]={guo[i].name,"",200,50,50,50,61,50,0,0};
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			sh[i]=0;du[i]=0;xz[i]=0;q[i]=0;bj[i]=i;xT[i]=0;gg[i]=0;si[i]=0;
			guo[i].tu=guo[i].name.substr(guo[i].name.length()-2,2);
			guo[i].tu+="土";while(guo[i].name.length()<8)guo[i].name+=" ";
			if(i==7||i==869)guo[i].tu="  土";
		}Y=2016;M=9;W=0;YY=0;MM=0;WW=1;
}
if(T==19){
	cnt=236;orz="老师";typ=0;ty=1;d1=20;d2=40;_=0;rev=0;
	int type[1024];
guo[1]={"白宗刚","",240,60,60,60,61,60,0,0};type[1]=11;
guo[2]={"蔡红","",300,75,75,75,76,75,0,0};type[2]=19;
guo[3]={"陈柏良","",360,90,90,90,100,90,0,0};type[3]=20;
guo[4]={"陈炳炉","",240,60,60,60,61,60,0,0};type[4]=10;
guo[5]={"陈昌勇","",240,60,60,60,61,60,0,0};type[5]=5;
guo[6]={"陈丹燕","",300,75,75,75,76,75,0,0};type[6]=13;
guo[7]={"陈锋","",351,87,87,87,91,90,0,0};type[7]=19;
guo[8]={"陈国成","",240,60,60,60,61,60,0,0};type[8]=17;
guo[9]={"陈浩","",240,60,60,60,61,60,0,0};type[9]=13;
guo[10]={"陈合力","",320,80,80,80,76,80,0,0};type[10]=14;
guo[11]={"陈华","",240,60,60,60,61,60,0,0};type[11]=9;
guo[12]={"陈佳骏","",240,60,60,60,61,60,0,0};type[12]=16;
guo[13]={"陈连原","",295,75,75,75,76,70,0,0};type[13]=9;
guo[14]={"陈龙珠","",240,60,60,60,61,60,0,0};type[14]=8;
guo[15]={"陈美琴","",240,60,60,60,61,60,0,0};type[15]=16;
guo[16]={"陈微微","",286,72,72,72,76,70,0,0};type[16]=14;
guo[17]={"陈小燕","",180,40,40,60,46,40,0,0};type[17]=7;
guo[18]={"陈雪萍","",260,65,65,65,65,65,0,0};type[18]=16;
guo[19]={"陈伊伊","",240,60,60,60,61,60,0,0};type[19]=15;
guo[20]={"陈依","",240,60,60,60,61,60,0,0};type[20]=8;
guo[21]={"陈义兵","",286,72,72,72,76,70,0,0};type[21]=11;
guo[22]={"陈忆宁","",240,60,60,60,61,60,0,0};type[22]=16;
guo[23]={"陈银伟","",380,95,95,95,106,95,0,0};type[23]=20;
guo[24]={"程加加","",240,60,60,60,61,60,0,0};type[24]=16;
guo[25]={"戴华敏","",240,60,60,60,61,60,0,0};type[25]=16;
guo[26]={"单兴妹","",180,40,40,60,46,40,0,0};type[26]=7;
guo[27]={"丁灿耀","",240,60,60,60,61,60,0,0};type[27]=9;
guo[28]={"丁金美","",240,60,60,60,61,60,0,0};type[28]=9;
guo[29]={"丁泾芳","",240,60,60,60,61,60,0,0};type[29]=8;
guo[30]={"丁素琴","",240,60,60,60,61,60,0,0};type[30]=3;
guo[31]={"丁雪艳","",240,60,60,60,61,60,0,0};type[31]=13;
guo[32]={"丁嫣然","",240,60,60,60,61,60,0,0};type[32]=2;
guo[33]={"董烨华","",105,15,15,60,16,15,0,0};type[33]=14;
guo[34]={"范国娟","",180,40,40,60,46,40,0,0};type[34]=1;
guo[35]={"范捷","",240,60,60,60,61,60,0,0};type[35]=8;
guo[36]={"范玲玲","",240,60,60,60,61,60,0,0};type[36]=16;
guo[37]={"方大林","",240,60,60,60,61,60,0,0};type[37]=10;
guo[38]={"费艳","",240,60,60,60,61,60,0,0};type[38]=12;
guo[39]={"冯报春","",240,60,60,60,61,60,0,0};type[39]=8;
guo[40]={"冯王亮","",340,85,85,85,91,85,0,0};type[40]=19;
guo[41]={"冯莹","",240,60,60,60,61,60,0,0};type[41]=3;
guo[42]={"傅芳芳","",240,60,60,60,61,60,0,0};type[42]=15;
guo[43]={"傅红霞","",240,60,60,60,61,60,0,0};type[43]=15;
guo[44]={"傅丽娜","",180,40,40,60,46,40,0,0};type[44]=1;
guo[45]={"傅雅飞","",240,60,60,60,61,60,0,0};type[45]=16;
guo[46]={"高英","",240,60,60,60,61,60,0,0};type[46]=15;
guo[47]={"葛雯雯","",180,40,40,60,46,40,0,0};type[47]=7;
guo[48]={"顾飞飞","",240,60,60,60,61,60,0,0};type[48]=9;
guo[49]={"顾向晖","",240,60,60,60,61,60,0,0};type[49]=15;
guo[50]={"顾秀芳","",240,60,60,60,61,60,0,0};type[50]=15;
guo[51]={"郭志威","",240,60,60,60,61,60,0,0};type[51]=2;
guo[52]={"韩冰","",240,60,60,60,61,60,0,0};type[52]=13;
guo[53]={"韩陈萍","",240,60,60,60,61,60,0,0};type[53]=5;
guo[54]={"韩小红","",240,60,60,60,61,60,0,0};type[54]=9;
guo[55]={"韩雨珊","",240,60,60,60,61,60,0,0};type[55]=9;
guo[56]={"何海明","",240,60,60,60,61,60,0,0};type[56]=13;
guo[57]={"何隽豪","",286,72,72,72,76,70,0,0};type[57]=10;
guo[58]={"何凯","",240,60,60,60,61,60,0,0};type[58]=3;
guo[59]={"何伟丹","",240,60,60,60,61,60,0,0};type[59]=10;
guo[60]={"洪波","",240,60,60,60,61,60,0,0};type[60]=16;
guo[61]={"侯磊","",180,40,40,60,46,40,0,0};type[61]=1;
guo[62]={"胡桂兰","",240,60,60,60,61,60,0,0};type[62]=17;
guo[63]={"胡红燕","",240,60,60,60,61,60,0,0};type[63]=6;
guo[64]={"胡建国","",240,60,60,60,61,60,0,0};type[64]=13;
guo[65]={"胡唯亚","",240,60,60,60,61,60,0,0};type[65]=2;
guo[66]={"胡勇","",240,60,60,60,61,60,0,0};type[66]=3;
guo[67]={"黄金裕","",240,60,60,60,61,60,0,0};type[67]=15;
guo[68]={"黄伟中","",240,60,60,60,61,60,0,0};type[68]=13;
guo[69]={"黄先辉","",240,60,60,60,61,60,0,0};type[69]=2;
guo[70]={"蒋明","",349,88,88,88,91,85,0,0};type[70]=20;
guo[71]={"金笛","",240,60,60,60,61,60,0,0};type[71]=17;
guo[72]={"金华元","",260,65,65,65,65,65,0,0};type[72]=5;
guo[73]={"金佳琳","",240,60,60,60,61,60,0,0};type[73]=9;
guo[74]={"金建忠","",286,72,72,72,76,70,0,0};type[74]=3;
guo[75]={"金江虹","",240,60,60,60,61,60,0,0};type[75]=9;
guo[76]={"孔君","",240,60,60,60,61,60,0,0};type[76]=15;
guo[77]={"孔利军","",240,60,60,60,61,60,0,0};type[77]=18;
guo[78]={"孔祥新","",240,60,60,60,61,60,0,0};type[78]=9;
guo[79]={"李岳信","",240,60,60,60,61,60,0,0};type[79]=3;
guo[80]={"郦章华","",240,60,60,60,61,60,0,0};type[80]=9;
guo[81]={"廖烨","",240,60,60,60,61,60,0,0};type[81]=15;
guo[82]={"林萍华","",340,85,85,85,91,85,0,0};type[82]=19;
guo[83]={"凌晓锋","",240,60,60,60,61,60,0,0};type[83]=9;
guo[84]={"刘军霞","",240,60,60,60,61,60,0,0};type[84]=8;
guo[85]={"刘明玉","",300,75,75,75,76,75,0,0};type[85]=19;
guo[86]={"刘淑芳","",240,60,60,60,61,60,0,0};type[86]=15;
guo[87]={"刘夏进","",331,82,82,82,91,85,0,0};type[87]=19;
guo[88]={"刘晓牛","",240,60,60,60,61,60,0,0};type[88]=9;
guo[89]={"楼开颜","",240,60,60,60,61,60,0,0};type[89]=13;
guo[90]={"楼立青","",240,60,60,60,61,60,0,0};type[90]=15;
guo[91]={"卢燎亚","",349,88,88,88,91,85,0,0};type[91]=20;
guo[92]={"卢卫红","",240,60,60,60,61,60,0,0};type[92]=12;
guo[93]={"鲁豪然","",240,60,60,60,61,60,0,0};type[93]=16;
guo[94]={"骆惠新","",240,60,60,60,61,60,0,0};type[94]=16;
guo[95]={"马丹娜","",240,60,60,60,61,60,0,0};type[95]=8;
guo[96]={"马作菁","",240,60,60,60,61,60,0,0};type[96]=2;
guo[97]={"孟德超","",240,60,60,60,61,60,0,0};type[97]=10;
guo[98]={"孟玲燕","",240,60,60,60,61,60,0,0};type[98]=14;
guo[99]={"孟伟强","",240,60,60,60,61,60,0,0};type[99]=9;
guo[100]={"聂云","",180,40,40,60,46,40,0,0};type[100]=7;
guo[101]={"彭爱波","",240,60,60,60,61,60,0,0};type[101]=17;
guo[102]={"平建树","",240,60,60,60,61,60,0,0};type[102]=5;
guo[103]={"祁倩","",180,40,40,60,46,40,0,0};type[103]=1;
guo[104]={"钱虹燕","",240,60,60,60,61,60,0,0};type[104]=15;
guo[105]={"秦黎","",240,60,60,60,61,60,0,0};type[105]=13;
guo[106]={"邱静娥","",240,60,60,60,61,60,0,0};type[106]=17;
guo[107]={"裘洪萍","",240,60,60,60,61,60,0,0};type[107]=15;
guo[108]={"阮国华","",240,60,60,60,61,60,0,0};type[108]=10;
guo[109]={"桑美娟","",240,60,60,60,61,60,0,0};type[109]=15;
guo[110]={"邵张彬","",240,60,60,60,61,60,0,0};type[110]=5;
guo[111]={"沈超华","",240,60,60,60,61,60,0,0};type[111]=3;
guo[112]={"沈初见","",286,72,72,72,76,70,0,0};type[112]=8;
guo[113]={"沈栋啸","",240,60,60,60,61,60,0,0};type[113]=9;
guo[114]={"沈剑蕾","",240,60,60,60,61,60,0,0};type[114]=15;
guo[115]={"沈祥土","",300,75,75,75,76,75,0,0};type[115]=19;
guo[116]={"沈洋铭","",240,60,60,60,61,60,0,0};type[116]=3;
guo[117]={"盛婷婷","",240,60,60,60,61,60,0,0};type[117]=15;
guo[118]={"施卡祥","",240,60,60,60,61,60,0,0};type[118]=13;
guo[119]={"施笑程","",300,75,75,75,76,75,0,0};type[119]=3;
guo[120]={"石谷颖","",240,60,60,60,61,60,0,0};type[120]=18;
guo[121]={"史伟芳","",180,40,40,60,46,40,0,0};type[121]=7;
guo[122]={"舒凤","",240,60,60,60,61,60,0,0};type[122]=6;
guo[123]={"宋弘韬","",240,60,60,60,61,60,0,0};type[123]=18;
guo[124]={"苏卫军","",291,72,72,72,76,75,0,0};type[124]=9;
guo[125]={"唐海燕","",240,60,60,60,61,60,0,0};type[125]=16;
guo[126]={"陶佳卉","",240,60,60,60,61,60,0,0};type[126]=8;
guo[127]={"童莉芳","",240,60,60,60,61,60,0,0};type[127]=6;
guo[128]={"汪陈帅","",240,60,60,60,61,60,0,0};type[128]=18;
guo[129]={"王柏根","",240,60,60,60,61,60,0,0};type[129]=1;
guo[130]={"王冰洁","",240,60,60,60,61,60,0,0};type[130]=10;
guo[131]={"王炳祥","",180,40,40,60,46,40,0,0};type[131]=1;
guo[132]={"王法新","",240,60,60,60,61,60,0,0};type[132]=5;
guo[133]={"王芳","",240,60,60,60,61,60,0,0};type[133]=15;
guo[134]={"王芳芳","",240,60,60,60,61,60,0,0};type[134]=17;
guo[135]={"王海燕","",280,70,70,70,76,70,0,0};type[135]=6;
guo[136]={"王洁","",240,60,60,60,61,60,0,0};type[136]=16;
guo[137]={"王晶晶","",300,75,75,75,76,75,0,0};type[137]=19;
guo[138]={"王宁","",240,60,60,60,61,60,0,0};type[138]=6;
guo[139]={"王佩金","",240,60,60,60,61,60,0,0};type[139]=18;
guo[140]={"王青","",180,40,40,60,46,40,0,0};type[140]=7;
guo[141]={"王琼娜","",240,60,60,60,61,60,0,0};type[141]=10;
guo[142]={"王姗姗","",240,60,60,60,61,60,0,0};type[142]=5;
guo[143]={"王维","",240,60,60,60,61,60,0,0};type[143]=15;
guo[144]={"王炜荣","",240,60,60,60,61,60,0,0};type[144]=3;
guo[145]={"王新东","",240,60,60,60,61,60,0,0};type[145]=16;
guo[146]={"王新璐","",240,60,60,60,61,60,0,0};type[146]=16;
guo[147]={"王学文","",240,60,60,60,61,60,0,0};type[147]=3;
guo[148]={"王燕","",286,72,72,72,76,70,0,0};type[148]=2;
guo[149]={"王一行","",240,60,60,60,61,60,0,0};type[149]=9;
guo[150]={"王幼青","",180,40,40,60,46,40,0,0};type[150]=1;
guo[151]={"王玉宇","",240,60,60,60,61,60,0,0};type[151]=15;
guo[152]={"王月","",240,60,60,60,61,60,0,0};type[152]=2;
guo[153]={"王月琴","",300,75,75,75,76,75,0,0};type[153]=16;
guo[154]={"魏杲","",180,40,40,60,46,40,0,0};type[154]=1;
guo[155]={"翁鹏飞","",240,60,60,60,61,60,0,0};type[155]=13;
guo[156]={"吴国年","",180,40,40,60,46,40,0,0};type[156]=1;
guo[157]={"吴军芳","",240,60,60,60,61,60,0,0};type[157]=4;
guo[158]={"吴丽娟","",240,60,60,60,61,60,0,0};type[158]=10;
guo[159]={"吴巍巍","",240,60,60,60,61,60,0,0};type[159]=16;
guo[160]={"夏帅波","",240,60,60,60,61,60,0,0};type[160]=16;
guo[161]={"谢澹","",286,72,72,72,76,70,0,0};type[161]=16;
guo[162]={"谢静超","",240,60,60,60,61,60,0,0};type[162]=15;
guo[163]={"谢君樑","",240,60,60,60,61,60,0,0};type[163]=3;
guo[164]={"谢月明","",240,60,60,60,61,60,0,0};type[164]=15;
guo[165]={"邢婷","",240,60,60,60,61,60,0,0};type[165]=3;
guo[166]={"邢秀英","",240,60,60,60,61,60,0,0};type[166]=15;
guo[167]={"徐凤碧","",240,60,60,60,61,60,0,0};type[167]=18;
guo[168]={"徐建光","",240,60,60,60,61,60,0,0};type[168]=11;
guo[169]={"徐立旦","",240,60,60,60,61,60,0,0};type[169]=15;
guo[170]={"徐萍","",240,60,60,60,61,60,0,0};type[170]=9;
guo[171]={"徐雯","",240,60,60,60,61,60,0,0};type[171]=2;
guo[172]={"许敏","",240,60,60,60,61,60,0,0};type[172]=16;
guo[173]={"许琪玫","",240,60,60,60,61,60,0,0};type[173]=17;
guo[174]={"许婷","",240,60,60,60,61,60,0,0};type[174]=11;
guo[175]={"宣桂林","",180,40,40,60,46,40,0,0};type[175]=7;
guo[176]={"闫彦彦","",240,60,60,60,61,60,0,0};type[176]=17;
guo[177]={"严淇","",240,60,60,60,61,60,0,0};type[177]=8;
guo[178]={"言利水","",240,60,60,60,61,60,0,0};type[178]=9;
guo[179]={"杨大为","",240,60,60,60,61,60,0,0};type[179]=15;
guo[180]={"杨国平","",286,72,72,72,76,70,0,0};type[180]=13;
guo[181]={"杨国仁","",240,60,60,60,61,60,0,0};type[181]=9;
guo[182]={"杨晶晶","",240,60,60,60,61,60,0,0};type[182]=15;
guo[183]={"杨菊妃","",240,60,60,60,61,60,0,0};type[183]=15;
guo[184]={"杨佩琼","",348,86,86,86,91,90,0,0};type[184]=19;
guo[185]={"杨瑞敏","",240,60,60,60,61,60,0,0};type[185]=9;
guo[186]={"杨炀","",240,60,60,60,61,60,0,0};type[186]=5;
guo[187]={"叶建红","",240,60,60,60,61,60,0,0};type[187]=16;
guo[188]={"叶建强","",240,60,60,60,61,60,0,0};type[188]=9;
guo[189]={"叶建映","",240,60,60,60,61,60,0,0};type[189]=15;
guo[190]={"叶佩莉","",286,72,72,72,76,70,0,0};type[190]=17;
guo[191]={"叶望尧","",340,85,85,85,91,85,0,0};type[191]=19;
guo[192]={"余栋材","",240,60,60,60,61,60,0,0};type[192]=14;
guo[193]={"余子兰","",240,60,60,60,61,60,0,0};type[193]=16;
guo[194]={"俞宝根","",240,60,60,60,61,60,0,0};type[194]=8;
guo[195]={"俞建种","",360,90,90,90,100,90,0,0};type[195]=20;
guo[196]={"俞苗锋","",240,60,60,60,61,60,0,0};type[196]=16;
guo[197]={"俞霞","",240,60,60,60,61,60,0,0};type[197]=3;
guo[198]={"俞笑晨","",240,60,60,60,61,60,0,0};type[198]=10;
guo[199]={"俞一凡","",240,60,60,60,61,60,0,0};type[199]=9;
guo[200]={"虞金龙","",286,72,72,72,76,70,0,0};type[200]=9;
guo[201]={"袁亚男","",240,60,60,60,61,60,0,0};type[201]=5;
guo[202]={"张超","",240,60,60,60,61,60,0,0};type[202]=2;
guo[203]={"张叠","",286,72,72,72,76,70,0,0};type[203]=5;
guo[204]={"张帆","",240,60,60,60,61,60,0,0};type[204]=4;
guo[205]={"张根灿","",240,60,60,60,61,60,0,0};type[205]=14;
guo[206]={"张豪","",240,60,60,60,61,60,0,0};type[206]=2;
guo[207]={"张坚秋","",240,60,60,60,61,60,0,0};type[207]=6;
guo[208]={"张江","",240,60,60,60,61,60,0,0};type[208]=3;
guo[209]={"张洁慧","",240,60,60,60,61,60,0,0};type[209]=16;
guo[210]={"张蕾","",286,72,72,72,76,70,0,0};type[210]=12;
guo[211]={"张璐吉","",240,60,60,60,61,60,0,0};type[211]=3;
guo[212]={"张伟丰","",240,60,60,60,61,60,0,0};type[212]=2;
guo[213]={"张小娟","",240,60,60,60,61,60,0,0};type[213]=13;
guo[214]={"张尧","",340,85,85,85,91,85,0,0};type[214]=19;
guo[215]={"张叶","",240,60,60,60,61,60,0,0};type[215]=13;
guo[216]={"张越爱","",180,40,40,60,46,40,0,0};type[216]=1;
guo[217]={"张卓燚","",240,60,60,60,61,60,0,0};type[217]=18;
guo[218]={"张祖农","",240,60,60,60,61,60,0,0};type[218]=9;
guo[219]={"赵正瑜","",240,60,60,60,61,60,0,0};type[219]=8;
guo[220]={"郑晴晴","",240,60,60,60,61,60,0,0};type[220]=8;
guo[221]={"郑小平","",240,60,60,60,61,60,0,0};type[221]=16;
guo[222]={"钟慧军","",240,60,60,60,61,60,0,0};type[222]=16;
guo[223]={"钟利华","",240,60,60,60,61,60,0,0};type[223]=12;
guo[224]={"周国才","",240,60,60,60,61,60,0,0};type[224]=10;
guo[225]={"周文龙","",269,68,68,68,61,65,0,0};type[225]=3;
guo[226]={"周文阳","",240,60,60,60,61,60,0,0};type[226]=13;
guo[227]={"朱谷兰","",240,60,60,60,61,60,0,0};type[227]=16;
guo[228]={"朱玛莉","",240,60,60,60,61,60,0,0};type[228]=4;
guo[229]={"朱时妙","",240,60,60,60,61,60,0,0};type[229]=13;
guo[230]={"朱水军","",346,87,87,87,91,85,0,0};type[230]=19;
guo[231]={"朱雯","",400,100,100,100,106,100,0,0};type[231]=20;
guo[232]={"朱媛","",240,60,60,60,61,60,0,0};type[232]=4;
guo[233]={"诸佳英","",240,60,60,60,61,60,0,0};type[233]=18;
guo[234]={"祝建强","",240,60,60,60,61,60,0,0};type[234]=14;
guo[235]={"祝智浩","",240,60,60,60,61,60,0,0};type[235]=13;
guo[236]={"??? (Playing with weaken someome)","",149,38,38,38,46,35,0,0};type[236]=0;
for(int i=1;i<=cnt;i++)for(int j=i+1;j<=cnt;j++){
	tu[i][j]=tu[j][i]=rand()%90+210;
	if(type[i]==type[j])tu[i][j]=tu[j][i]=min(tu[i][j],rand()%90+10);
	if(type[i]>18&&type[j]<19)tu[i][j]+=200,tu[j][i]+=200;
	if(type[j]>18&&type[i]<19)tu[i][j]+=200,tu[j][i]+=200;
	if(type[j]==0&&guo[i].guoli<200&&guo[i].guoli>150)tu[i][j]-=200,tu[j][i]-=190; 
}
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			sh[i]=0;du[i]=0;xz[i]=0;q[i]=0;bj[i]=i;xT[i]=0;gg[i]=0;si[i]=0;
			guo[i].tu=guo[i].name.substr(guo[i].name.length()-2,2);
			guo[i].tu+="土";if(i==236)guo[i].tu="妖土";if(i==115)guo[i].tu="祥土";
		}Y=2018;M=9;W=0;YY=0;MM=0;WW=1;
}
if(T==23){
	cnt=1108;orz="同学或老师";typ=0;ty=1;d1=20;d2=40;_=0;rev=1;
	fr[8][1045]=fr[1045][8]=fr[8][884]=fr[884][8]=fr[1045][884]=fr[884][1045]=1;
	int ran=rand()&1?539:80;
	fr[8][80]=fr[80][8]=fr[80][884]=fr[884][80]=fr[1045][80]=fr[80][1045]=1;
	fr[8][539]=fr[539][8]=fr[539][884]=fr[884][539]=fr[1045][539]=fr[539][1045]=1;
	fr[34][884]=fr[884][34]=fr[8][583]=fr[583][8]=fr[539][80]=fr[80][539]=1;
	fr[705][1000]=fr[705][1032]=fr[1000][1032]=fr[1032][1000]=fr[1032][705]=fr[1000][705]=1;
	fr[705][1059]=fr[1059][1032]=fr[1000][1059]=fr[1059][1000]=fr[1032][1059]=fr[1059][705]=1;
	fr[239][574]=fr[239][857]=fr[574][857]=fr[857][574]=fr[857][239]=fr[574][239]=1;
	int type[2048];
guo[1]={"敖以恒","",160,40,40,40,46,40,0,0};type[1]=-4;
guo[2]={"白宗刚","",240,60,60,60,61,60,0,0};type[2]=11;
guo[3]={"班越童","",160,40,40,40,46,40,0,0};type[3]=-11;
guo[4]={"包菁菁","",160,40,40,40,46,40,0,0};type[4]=-5;
guo[5]={"包灵怡","",160,40,40,40,46,40,0,0};type[5]=-10;
guo[6]={"包文涵","",160,40,40,40,46,40,0,0};type[6]=-12;
guo[7]={"包逸昊","",160,40,40,40,46,40,0,0};type[7]=-2;
guo[8]={"鲍东方","",160,40,40,40,46,40,0,0};type[8]=-10;
guo[9]={"鲍荣瑜","",160,40,40,40,46,40,0,0};type[9]=-4;
guo[10]={"鲍睿阳","",160,40,40,40,46,40,0,0};type[10]=-10;
guo[11]={"鲍文清","",160,40,40,40,46,40,0,0};type[11]=-5;
guo[12]={"鲍易韬","",160,40,40,40,46,40,0,0};type[12]=-12;
guo[13]={"鲍逸娴","",160,40,40,40,46,40,0,0};type[13]=-14;
guo[14]={"蔡格非","",160,40,40,40,46,40,0,0};type[14]=-15;
guo[15]={"蔡红","",300,75,75,75,76,75,0,0};type[15]=19;
guo[16]={"蔡晶晶","",160,40,40,40,46,40,0,0};type[16]=-1;
guo[17]={"蔡元熠","",160,40,40,40,46,40,0,0};type[17]=-12;
guo[18]={"曹成灿","",160,40,40,40,46,40,0,0};type[18]=-2;
guo[19]={"曹依宁","",160,40,40,40,46,40,0,0};type[19]=-1;
guo[20]={"曹雨琦","",160,40,40,40,46,40,0,0};type[20]=-5;
guo[21]={"曹周川","",160,40,40,40,46,40,0,0};type[21]=-3;
guo[22]={"岑明祥","",160,40,40,40,46,40,0,0};type[22]=-11;
guo[23]={"柴宇栋","",160,40,40,40,46,40,0,0};type[23]=-7;
guo[24]={"柴雨诗","",160,40,40,40,46,40,0,0};type[24]=-15;
guo[25]={"常琳","",160,40,40,40,46,40,0,0};type[25]=-1;
guo[26]={"车央菲","",160,40,40,40,46,40,0,0};type[26]=-14;
guo[27]={"陈柏良","",360,90,90,90,100,90,0,0};type[27]=20;
guo[28]={"陈彬","",160,40,40,40,46,40,0,0};type[28]=-2;
guo[29]={"陈炳炉","",240,60,60,60,61,60,0,0};type[29]=10;
guo[30]={"陈昌勇","",240,60,60,60,61,60,0,0};type[30]=5;
guo[31]={"陈程帆","",160,40,40,40,46,40,0,0};type[31]=-2;
guo[32]={"陈聪","",160,40,40,40,46,40,0,0};type[32]=-9;
guo[33]={"陈丹","",160,40,40,40,46,40,0,0};type[33]=-6;
guo[34]={"陈丹燕","",300,75,75,75,76,75,0,0};type[34]=13;
guo[35]={"陈锋","",351,87,87,87,91,90,0,0};type[35]=19;
guo[36]={"陈公泱","",160,40,40,40,46,40,0,0};type[36]=-2;
guo[37]={"陈国成","",240,60,60,60,61,60,0,0};type[37]=17;
guo[38]={"陈昊","",160,40,40,40,46,40,0,0};type[38]=-9;
guo[39]={"陈浩","",240,60,60,60,61,60,0,0};type[39]=13;
guo[40]={"陈浩","",160,40,40,40,46,40,0,0};type[40]=-3;
guo[41]={"陈合力","",320,80,80,80,76,80,0,0};type[41]=14;
guo[42]={"陈华","",240,60,60,60,61,60,0,0};type[42]=9;
guo[43]={"陈佳骏","",240,60,60,60,61,60,0,0};type[43]=16;
guo[44]={"陈佳琰","",160,40,40,40,46,40,0,0};type[44]=-1;
guo[45]={"陈佳颖","",160,40,40,40,46,40,0,0};type[45]=-1;
guo[46]={"陈嘉豪","",160,40,40,40,46,40,0,0};type[46]=-3;
guo[47]={"陈江南","",160,40,40,40,46,40,0,0};type[47]=-8;
guo[48]={"陈锦涛","",160,40,40,40,46,40,0,0};type[48]=-13;
guo[49]={"陈凯颖","",160,40,40,40,46,40,0,0};type[49]=-14;
guo[50]={"陈立","",160,40,40,40,46,40,0,0};type[50]=-13;
guo[51]={"陈连原","",295,75,75,75,76,70,0,0};type[51]=9;
guo[52]={"陈龙翀","",160,40,40,40,46,40,0,0};type[52]=-10;
guo[53]={"陈龙珠","",240,60,60,60,61,60,0,0};type[53]=8;
guo[54]={"陈美琴","",240,60,60,60,61,60,0,0};type[54]=16;
guo[55]={"陈明洁","",160,40,40,40,46,40,0,0};type[55]=-1;
guo[56]={"陈鸣赛","",160,40,40,40,46,40,0,0};type[56]=-14;
guo[57]={"陈诺","",160,40,40,40,46,40,0,0};type[57]=-13;
guo[58]={"陈齐治","",160,40,40,40,46,40,0,0};type[58]=-10;
guo[59]={"陈启楠","",160,40,40,40,46,40,0,0};type[59]=-2;
guo[60]={"陈沁怡","",160,40,40,40,46,40,0,0};type[60]=-7;
guo[61]={"陈沁芸","",160,40,40,40,46,40,0,0};type[61]=-3;
guo[62]={"陈青霞","",160,40,40,40,46,40,0,0};type[62]=-1;
guo[63]={"陈少楠","",160,40,40,40,46,40,0,0};type[63]=-9;
guo[64]={"陈诗楠","",160,40,40,40,46,40,0,0};type[64]=-14;
guo[65]={"陈仕辰","",160,40,40,40,46,40,0,0};type[65]=-14;
guo[66]={"陈姝烨","",160,40,40,40,46,40,0,0};type[66]=-5;
guo[67]={"陈思诺","",160,40,40,40,46,40,0,0};type[67]=-3;
guo[68]={"陈思源","",160,40,40,40,46,40,0,0};type[68]=-11;
guo[69]={"陈天宇","",160,40,40,40,46,40,0,0};type[69]=-11;
guo[70]={"陈威","",160,40,40,40,46,40,0,0};type[70]=-6;
guo[71]={"陈微微","",286,72,72,72,76,70,0,0};type[71]=14;
guo[72]={"陈曦","",160,40,40,40,46,40,0,0};type[72]=-7;
guo[73]={"陈小燕","",210,50,50,60,46,50,0,0};type[73]=7;
guo[74]={"陈晓烨","",160,40,40,40,46,40,0,0};type[74]=-12;
guo[75]={"陈晓玥","",160,40,40,40,46,40,0,0};type[75]=-4;
guo[76]={"陈欣雨","",160,40,40,40,46,40,0,0};type[76]=-11;
guo[77]={"陈新","",160,40,40,40,46,40,0,0};type[77]=-11;
guo[78]={"陈星悦","",160,40,40,40,46,40,0,0};type[78]=-9;
guo[79]={"陈幸媛","",160,40,40,40,46,40,0,0};type[79]=-13;
guo[80]={"陈雪萍","",260,65,65,65,65,65,0,0};type[80]=16;
guo[81]={"陈叶清","",160,40,40,40,46,40,0,0};type[81]=-12;
guo[82]={"陈烨霏","",160,40,40,40,46,40,0,0};type[82]=-8;
guo[83]={"陈一鸣","",160,40,40,40,46,40,0,0};type[83]=-6;
guo[84]={"陈伊伊","",240,60,60,60,61,60,0,0};type[84]=15;
guo[85]={"陈依","",240,60,60,60,61,60,0,0};type[85]=8;
guo[86]={"陈依娜","",160,40,40,40,46,40,0,0};type[86]=-16;
guo[87]={"陈祎涵","",160,40,40,40,46,40,0,0};type[87]=-8;
guo[88]={"陈怡洁","",160,40,40,40,46,40,0,0};type[88]=-6;
guo[89]={"陈以非","",160,40,40,40,46,40,0,0};type[89]=-15;
guo[90]={"陈义兵","",286,72,72,72,76,70,0,0};type[90]=11;
guo[91]={"陈忆宁","",240,60,60,60,61,60,0,0};type[91]=16;
guo[92]={"陈奕然","",160,40,40,40,46,40,0,0};type[92]=-13;
guo[93]={"陈益强","",160,40,40,40,46,40,0,0};type[93]=-3;
guo[94]={"陈益扬","",160,40,40,40,46,40,0,0};type[94]=-13;
guo[95]={"陈银伟","",380,95,95,95,106,95,0,0};type[95]=20;
guo[96]={"陈颖超","",160,40,40,40,46,40,0,0};type[96]=-8;
guo[97]={"陈颖楠","",160,40,40,40,46,40,0,0};type[97]=-1;
guo[98]={"陈羽柯","",160,40,40,40,46,40,0,0};type[98]=-1;
guo[99]={"陈雨珂","",160,40,40,40,46,40,0,0};type[99]=-13;
guo[100]={"陈泽浩","",160,40,40,40,46,40,0,0};type[100]=-9;
guo[101]={"陈震泽","",160,40,40,40,46,40,0,0};type[101]=-12;
guo[102]={"陈之楷","",160,40,40,40,46,40,0,0};type[102]=0;
guo[103]={"陈卓政","",160,40,40,40,46,40,0,0};type[103]=-15;
guo[104]={"成倩汝","",160,40,40,40,46,40,0,0};type[104]=-4;
guo[105]={"程刚","",160,40,40,40,46,40,0,0};type[105]=-2;
guo[106]={"程加加","",240,60,60,60,61,60,0,0};type[106]=16;
guo[107]={"程杰","",160,40,40,40,46,40,0,0};type[107]=-7;
guo[108]={"程诺","",160,40,40,40,46,40,0,0};type[108]=-4;
guo[109]={"褚步霄","",160,40,40,40,46,40,0,0};type[109]=-10;
guo[110]={"崔佳文","",160,40,40,40,46,40,0,0};type[110]=-16;
guo[111]={"崔立添","",160,40,40,40,46,40,0,0};type[111]=-15;
guo[112]={"崔洲映","",160,40,40,40,46,40,0,0};type[112]=-10;
guo[113]={"戴华敏","",240,60,60,60,61,60,0,0};type[113]=16;
guo[114]={"戴立奇","",160,40,40,40,46,40,0,0};type[114]=-11;
guo[115]={"戴世达","",160,40,40,40,46,40,0,0};type[115]=-8;
guo[116]={"单佳梦","",160,40,40,40,46,40,0,0};type[116]=-4;
guo[117]={"单松涛","",160,40,40,40,46,40,0,0};type[117]=-5;
guo[118]={"单王杰","",160,40,40,40,46,40,0,0};type[118]=-1;
guo[119]={"单兴妹","",210,50,50,60,46,50,0,0};type[119]=7;
guo[120]={"单雨恬","",160,40,40,40,46,40,0,0};type[120]=-15;
guo[121]={"单昱呈","",160,40,40,40,46,40,0,0};type[121]=-9;
guo[122]={"单子渐","",160,40,40,40,46,40,0,0};type[122]=-5;
guo[123]={"邓仁杰","",160,40,40,40,46,40,0,0};type[123]=-7;
guo[124]={"邓宇鑫","",160,40,40,40,46,40,0,0};type[124]=-12;
guo[125]={"丁博毅","",160,40,40,40,46,40,0,0};type[125]=-3;
guo[126]={"丁灿耀","",240,60,60,60,61,60,0,0};type[126]=9;
guo[127]={"丁程阳","",160,40,40,40,46,40,0,0};type[127]=-6;
guo[128]={"丁惠峰","",160,40,40,40,46,40,0,0};type[128]=-14;
guo[129]={"丁佳尔","",160,40,40,40,46,40,0,0};type[129]=-1;
guo[130]={"丁嘉浩","",160,40,40,40,46,40,0,0};type[130]=-6;
guo[131]={"丁金美","",240,60,60,60,61,60,0,0};type[131]=9;
guo[132]={"丁泾芳","",240,60,60,60,61,60,0,0};type[132]=8;
guo[133]={"丁纳川","",160,40,40,40,46,40,0,0};type[133]=-14;
guo[134]={"丁纳海","",160,40,40,40,46,40,0,0};type[134]=-1;
guo[135]={"丁奇瑶","",160,40,40,40,46,40,0,0};type[135]=-5;
guo[136]={"丁素琴","",240,60,60,60,61,60,0,0};type[136]=3;
guo[137]={"丁雪艳","",240,60,60,60,61,60,0,0};type[137]=13;
guo[138]={"丁嫣然","",240,60,60,60,61,60,0,0};type[138]=2;
guo[139]={"丁阳","",160,40,40,40,46,40,0,0};type[139]=-3;
guo[140]={"丁伊娜","",160,40,40,40,46,40,0,0};type[140]=-6;
guo[141]={"丁奕楠","",160,40,40,40,46,40,0,0};type[141]=-5;
guo[142]={"丁颖","",160,40,40,40,46,40,0,0};type[142]=-14;
guo[143]={"丁祝涛","",160,40,40,40,46,40,0,0};type[143]=-11;
guo[144]={"董炬悦","",160,40,40,40,46,40,0,0};type[144]=-9;
guo[145]={"董天禹","",160,40,40,40,46,40,0,0};type[145]=-2;
guo[146]={"董恬恬","",160,40,40,40,46,40,0,0};type[146]=-8;
guo[147]={"董翔宇","",160,40,40,40,46,40,0,0};type[147]=-7;
guo[148]={"董雪珂","",160,40,40,40,46,40,0,0};type[148]=-8;
guo[149]={"董烨华","",105,15,15,60,16,15,0,0};type[149]=14;
guo[150]={"董振皓","",160,40,40,40,46,40,0,0};type[150]=-12;
guo[151]={"董之瑜","",160,40,40,40,46,40,0,0};type[151]=-8;
guo[152]={"杜晗晨","",160,40,40,40,46,40,0,0};type[152]=-9;
guo[153]={"杜天意","",160,40,40,40,46,40,0,0};type[153]=-11;
guo[154]={"杜逍云","",160,40,40,40,46,40,0,0};type[154]=-13;
guo[155]={"杜心怡","",160,40,40,40,46,40,0,0};type[155]=-16;
guo[156]={"杜依","",160,40,40,40,46,40,0,0};type[156]=-2;
guo[157]={"杜依晗","",160,40,40,40,46,40,0,0};type[157]=-14;
guo[158]={"樊豪成","",160,40,40,40,46,40,0,0};type[158]=-16;
guo[159]={"樊任辉","",160,40,40,40,46,40,0,0};type[159]=-1;
guo[160]={"樊晓珂","",160,40,40,40,46,40,0,0};type[160]=-5;
guo[161]={"范丁晨","",160,40,40,40,46,40,0,0};type[161]=-11;
guo[162]={"范国娟","",210,50,50,60,46,50,0,0};type[162]=1;
guo[163]={"范捷","",240,60,60,60,61,60,0,0};type[163]=8;
guo[164]={"范玲玲","",240,60,60,60,61,60,0,0};type[164]=16;
guo[165]={"范文意","",160,40,40,40,46,40,0,0};type[165]=-8;
guo[166]={"方大林","",240,60,60,60,61,60,0,0};type[166]=10;
guo[167]={"方高峰","",160,40,40,40,46,40,0,0};type[167]=-7;
guo[168]={"方沁奕","",160,40,40,40,46,40,0,0};type[168]=-13;
guo[169]={"方震","",160,40,40,40,46,40,0,0};type[169]=-10;
guo[170]={"费艳","",240,60,60,60,61,60,0,0};type[170]=12;
guo[171]={"费喆","",160,40,40,40,46,40,0,0};type[171]=-15;
guo[172]={"封岑琦","",160,40,40,40,46,40,0,0};type[172]=-1;
guo[173]={"封姚逸","",160,40,40,40,46,40,0,0};type[173]=-16;
guo[174]={"封卓宁","",160,40,40,40,46,40,0,0};type[174]=-4;
guo[175]={"冯报春","",240,60,60,60,61,60,0,0};type[175]=8;
guo[176]={"冯诚君","",160,40,40,40,46,40,0,0};type[176]=-14;
guo[177]={"冯佳依","",160,40,40,40,46,40,0,0};type[177]=-8;
guo[178]={"冯可树","",160,40,40,40,46,40,0,0};type[178]=-2;
guo[179]={"冯沁悦","",160,40,40,40,46,40,0,0};type[179]=-7;
guo[180]={"冯天祺","",160,40,40,40,46,40,0,0};type[180]=-2;
guo[181]={"冯王亮","",340,85,85,85,91,85,0,0};type[181]=19;
guo[182]={"冯奕婷","",160,40,40,40,46,40,0,0};type[182]=-14;
guo[183]={"冯莹","",240,60,60,60,61,60,0,0};type[183]=3;
guo[184]={"冯滢","",160,40,40,40,46,40,0,0};type[184]=-7;
guo[185]={"冯宇飞","",160,40,40,40,46,40,0,0};type[185]=-13;
guo[186]={"冯泽越","",160,40,40,40,46,40,0,0};type[186]=-12;
guo[187]={"冯周","",160,40,40,40,46,40,0,0};type[187]=-13;
guo[188]={"付晨阳","",160,40,40,40,46,40,0,0};type[188]=-3;
guo[189]={"付诗昊","",160,40,40,40,46,40,0,0};type[189]=-10;
guo[190]={"傅芳芳","",240,60,60,60,61,60,0,0};type[190]=15;
guo[191]={"傅红霞","",240,60,60,60,61,60,0,0};type[191]=15;
guo[192]={"傅佳雯","",160,40,40,40,46,40,0,0};type[192]=-6;
guo[193]={"傅杰郁阳","",160,40,40,40,46,40,0,0};type[193]=-9;
guo[194]={"傅君扬","",160,40,40,40,46,40,0,0};type[194]=0;
guo[195]={"傅俊杰","",160,40,40,40,46,40,0,0};type[195]=-3;
guo[196]={"傅乐天","",160,40,40,40,46,40,0,0};type[196]=-10;
guo[197]={"傅丽娜","",210,50,50,60,46,50,0,0};type[197]=1;
guo[198]={"傅鹏宇","",160,40,40,40,46,40,0,0};type[198]=-16;
guo[199]={"傅文杰","",160,40,40,40,46,40,0,0};type[199]=-1;
guo[200]={"傅雪艺","",160,40,40,40,46,40,0,0};type[200]=-9;
guo[201]={"傅雅飞","",240,60,60,60,61,60,0,0};type[201]=16;
guo[202]={"傅烨雷","",160,40,40,40,46,40,0,0};type[202]=-8;
guo[203]={"傅依雯","",160,40,40,40,46,40,0,0};type[203]=-10;
guo[204]={"傅咏烽","",160,40,40,40,46,40,0,0};type[204]=-2;
guo[205]={"傅雨涵","",160,40,40,40,46,40,0,0};type[205]=-15;
guo[206]={"傅樟明","",160,40,40,40,46,40,0,0};type[206]=-5;
guo[207]={"干博","",160,40,40,40,46,40,0,0};type[207]=-3;
guo[208]={"高成","",160,40,40,40,46,40,0,0};type[208]=-16;
guo[209]={"高胜男","",160,40,40,40,46,40,0,0};type[209]=-14;
guo[210]={"高雅雯","",160,40,40,40,46,40,0,0};type[210]=-8;
guo[211]={"高宜骋","",160,40,40,40,46,40,0,0};type[211]=-1;
guo[212]={"高屹雯","",160,40,40,40,46,40,0,0};type[212]=0;
guo[213]={"高英","",240,60,60,60,61,60,0,0};type[213]=15;
guo[214]={"高瑜","",160,40,40,40,46,40,0,0};type[214]=-2;
guo[215]={"高源","",160,40,40,40,46,40,0,0};type[215]=-3;
guo[216]={"葛俏青","",160,40,40,40,46,40,0,0};type[216]=-8;
guo[217]={"葛雯雯","",210,50,50,60,46,50,0,0};type[217]=7;
guo[218]={"葛欣媛","",160,40,40,40,46,40,0,0};type[218]=-11;
guo[219]={"顾朝源","",160,40,40,40,46,40,0,0};type[219]=-3;
guo[220]={"顾飞飞","",240,60,60,60,61,60,0,0};type[220]=9;
guo[221]={"顾家俊","",160,40,40,40,46,40,0,0};type[221]=-13;
guo[222]={"顾向晖","",240,60,60,60,61,60,0,0};type[222]=15;
guo[223]={"顾秀芳","",240,60,60,60,61,60,0,0};type[223]=15;
guo[224]={"顾依珂","",160,40,40,40,46,40,0,0};type[224]=-6;
guo[225]={"顾熠","",160,40,40,40,46,40,0,0};type[225]=-8;
guo[226]={"郭佳燕","",160,40,40,40,46,40,0,0};type[226]=-12;
guo[227]={"郭楠","",160,40,40,40,46,40,0,0};type[227]=-10;
guo[228]={"郭杨杰","",160,40,40,40,46,40,0,0};type[228]=-16;
guo[229]={"郭艺琳","",160,40,40,40,46,40,0,0};type[229]=-5;
guo[230]={"郭羽晨","",160,40,40,40,46,40,0,0};type[230]=-6;
guo[231]={"郭芷渝","",160,40,40,40,46,40,0,0};type[231]=-5;
guo[232]={"郭志威","",240,60,60,60,61,60,0,0};type[232]=2;
guo[233]={"韩冰","",240,60,60,60,61,60,0,0};type[233]=13;
guo[234]={"韩陈萍","",240,60,60,60,61,60,0,0};type[234]=5;
guo[235]={"韩慧瑜","",160,40,40,40,46,40,0,0};type[235]=-8;
guo[236]={"韩孟霖","",160,40,40,40,46,40,0,0};type[236]=-16;
guo[237]={"韩启煊","",160,40,40,40,46,40,0,0};type[237]=-12;
guo[238]={"韩求是","",160,40,40,40,46,40,0,0};type[238]=-6;
guo[239]={"韩小红","",240,60,60,60,61,60,0,0};type[239]=9;
guo[240]={"韩一洲","",160,40,40,40,46,40,0,0};type[240]=-1;
guo[241]={"韩怡添","",160,40,40,40,46,40,0,0};type[241]=-4;
guo[242]={"韩雨珊","",240,60,60,60,61,60,0,0};type[242]=9;
guo[243]={"何晨泽","",160,40,40,40,46,40,0,0};type[243]=-10;
guo[244]={"何楚楚","",160,40,40,40,46,40,0,0};type[244]=-14;
guo[245]={"何东彦","",160,40,40,40,46,40,0,0};type[245]=-4;
guo[246]={"何海明","",240,60,60,60,61,60,0,0};type[246]=13;
guo[247]={"何怀真","",160,40,40,40,46,40,0,0};type[247]=-4;
guo[248]={"何霁寒","",160,40,40,40,46,40,0,0};type[248]=-2;
guo[249]={"何家琦","",160,40,40,40,46,40,0,0};type[249]=-2;
guo[250]={"何隽豪","",286,72,72,72,76,70,0,0};type[250]=10;
guo[251]={"何凯","",240,60,60,60,61,60,0,0};type[251]=3;
guo[252]={"何恺昱","",160,40,40,40,46,40,0,0};type[252]=-4;
guo[253]={"何旻涵","",160,40,40,40,46,40,0,0};type[253]=-12;
guo[254]={"何睿","",160,40,40,40,46,40,0,0};type[254]=0;
guo[255]={"何赛飞","",160,40,40,40,46,40,0,0};type[255]=-8;
guo[256]={"何仕阳","",160,40,40,40,46,40,0,0};type[256]=-15;
guo[257]={"何伟丹","",240,60,60,60,61,60,0,0};type[257]=10;
guo[258]={"何心仪","",160,40,40,40,46,40,0,0};type[258]=-1;
guo[259]={"何星仪","",160,40,40,40,46,40,0,0};type[259]=-15;
guo[260]={"何雪雯","",160,40,40,40,46,40,0,0};type[260]=-11;
guo[261]={"何彦仪","",160,40,40,40,46,40,0,0};type[261]=-14;
guo[262]={"何晏清","",160,40,40,40,46,40,0,0};type[262]=-4;
guo[263]={"何烨超","",160,40,40,40,46,40,0,0};type[263]=-9;
guo[264]={"何怡鼎","",160,40,40,40,46,40,0,0};type[264]=-11;
guo[265]={"何逸飞","",160,40,40,40,46,40,0,0};type[265]=-8;
guo[266]={"何越菲","",160,40,40,40,46,40,0,0};type[266]=-8;
guo[267]={"何志强","",160,40,40,40,46,40,0,0};type[267]=-12;
guo[268]={"洪波","",240,60,60,60,61,60,0,0};type[268]=16;
guo[269]={"洪佳莉","",160,40,40,40,46,40,0,0};type[269]=-14;
guo[270]={"洪珂凡","",160,40,40,40,46,40,0,0};type[270]=-5;
guo[271]={"洪依婷","",160,40,40,40,46,40,0,0};type[271]=-5;
guo[272]={"侯磊","",210,50,50,60,46,50,0,0};type[272]=1;
guo[273]={"胡冰清","",160,40,40,40,46,40,0,0};type[273]=-4;
guo[274]={"胡城豪","",160,40,40,40,46,40,0,0};type[274]=-9;
guo[275]={"胡董阳","",160,40,40,40,46,40,0,0};type[275]=-9;
guo[276]={"胡桂兰","",240,60,60,60,61,60,0,0};type[276]=17;
guo[277]={"胡寒昱","",160,40,40,40,46,40,0,0};type[277]=-12;
guo[278]={"胡红燕","",240,60,60,60,61,60,0,0};type[278]=6;
guo[279]={"胡建国","",240,60,60,60,61,60,0,0};type[279]=13;
guo[280]={"胡凯捷","",160,40,40,40,46,40,0,0};type[280]=-10;
guo[281]={"胡楷其","",160,40,40,40,46,40,0,0};type[281]=-15;
guo[282]={"胡乐怡","",160,40,40,40,46,40,0,0};type[282]=-6;
guo[283]={"胡琳妍","",160,40,40,40,46,40,0,0};type[283]=-14;
guo[284]={"胡宁泱","",160,40,40,40,46,40,0,0};type[284]=-6;
guo[285]={"胡鹏飞","",160,40,40,40,46,40,0,0};type[285]=-1;
guo[286]={"胡琪琦","",160,40,40,40,46,40,0,0};type[286]=-5;
guo[287]={"胡乔桦","",160,40,40,40,46,40,0,0};type[287]=-9;
guo[288]={"胡杉","",160,40,40,40,46,40,0,0};type[288]=-12;
guo[289]={"胡唯亚","",240,60,60,60,61,60,0,0};type[289]=2;
guo[290]={"胡欣瑜","",160,40,40,40,46,40,0,0};type[290]=-16;
guo[291]={"胡一涛","",160,40,40,40,46,40,0,0};type[291]=-11;
guo[292]={"胡垠霞","",160,40,40,40,46,40,0,0};type[292]=-12;
guo[293]={"胡颖","",160,40,40,40,46,40,0,0};type[293]=-12;
guo[294]={"胡勇","",240,60,60,60,61,60,0,0};type[294]=3;
guo[295]={"胡语涵","",160,40,40,40,46,40,0,0};type[295]=-4;
guo[296]={"胡蕴文","",160,40,40,40,46,40,0,0};type[296]=-1;
guo[297]={"胡哲昊","",160,40,40,40,46,40,0,0};type[297]=-10;
guo[298]={"黄杭旗","",160,40,40,40,46,40,0,0};type[298]=-12;
guo[299]={"黄浩瀚","",160,40,40,40,46,40,0,0};type[299]=-3;
guo[300]={"黄嘉宝","",160,40,40,40,46,40,0,0};type[300]=-12;
guo[301]={"黄江英","",160,40,40,40,46,40,0,0};type[301]=-4;
guo[302]={"黄金裕","",240,60,60,60,61,60,0,0};type[302]=15;
guo[303]={"黄乐了","",160,40,40,40,46,40,0,0};type[303]=-11;
guo[304]={"黄丽燕","",160,40,40,40,46,40,0,0};type[304]=-4;
guo[305]={"黄睿琳","",160,40,40,40,46,40,0,0};type[305]=-13;
guo[306]={"黄伟中","",240,60,60,60,61,60,0,0};type[306]=13;
guo[307]={"黄先辉","",240,60,60,60,61,60,0,0};type[307]=2;
guo[308]={"黄勇","",160,40,40,40,46,40,0,0};type[308]=-2;
guo[309]={"黄雨楚","",160,40,40,40,46,40,0,0};type[309]=-1;
guo[310]={"惠雷","",160,40,40,40,46,40,0,0};type[310]=-2;
guo[311]={"纪冬颖","",160,40,40,40,46,40,0,0};type[311]=-9;
guo[312]={"季佳怡","",160,40,40,40,46,40,0,0};type[312]=-15;
guo[313]={"季羽凝","",160,40,40,40,46,40,0,0};type[313]=-7;
guo[314]={"贾谷兰","",160,40,40,40,46,40,0,0};type[314]=-13;
guo[315]={"江子焕","",160,40,40,40,46,40,0,0};type[315]=-5;
guo[316]={"蒋东昊","",160,40,40,40,46,40,0,0};type[316]=-9;
guo[317]={"蒋海斌","",160,40,40,40,46,40,0,0};type[317]=-2;
guo[318]={"蒋鸿程","",160,40,40,40,46,40,0,0};type[318]=-12;
guo[319]={"蒋明","",349,88,88,88,91,85,0,0};type[319]=20;
guo[320]={"蒋思瑜","",160,40,40,40,46,40,0,0};type[320]=-1;
guo[321]={"蒋王英","",160,40,40,40,46,40,0,0};type[321]=-13;
guo[322]={"蒋晓能","",160,40,40,40,46,40,0,0};type[322]=-14;
guo[323]={"蒋易杰","",160,40,40,40,46,40,0,0};type[323]=-10;
guo[324]={"蒋泽华","",160,40,40,40,46,40,0,0};type[324]=-14;
guo[325]={"蒋志锴","",160,40,40,40,46,40,0,0};type[325]=-9;
guo[326]={"蒋卓颖","",160,40,40,40,46,40,0,0};type[326]=-16;
guo[327]={"金驰凯","",160,40,40,40,46,40,0,0};type[327]=0;
guo[328]={"金笛","",240,60,60,60,61,60,0,0};type[328]=17;
guo[329]={"金典","",160,40,40,40,46,40,0,0};type[329]=-15;
guo[330]={"金观能","",160,40,40,40,46,40,0,0};type[330]=-7;
guo[331]={"金华元","",260,65,65,65,65,65,0,0};type[331]=5;
guo[332]={"金佳琳","",240,60,60,60,61,60,0,0};type[332]=9;
guo[333]={"金佳萍","",160,40,40,40,46,40,0,0};type[333]=-9;
guo[334]={"金建忠","",286,72,72,72,76,70,0,0};type[334]=3;
guo[335]={"金江虹","",240,60,60,60,61,60,0,0};type[335]=9;
guo[336]={"金洁","",160,40,40,40,46,40,0,0};type[336]=-3;
guo[337]={"金璟","",160,40,40,40,46,40,0,0};type[337]=-2;
guo[338]={"金灵锋","",160,40,40,40,46,40,0,0};type[338]=-4;
guo[339]={"金灵旷怡","",160,40,40,40,46,40,0,0};type[339]=0;
guo[340]={"金铭萱","",160,40,40,40,46,40,0,0};type[340]=-6;
guo[341]={"金能","",160,40,40,40,46,40,0,0};type[341]=0;
guo[342]={"金诗雨","",160,40,40,40,46,40,0,0};type[342]=0;
guo[343]={"金思远","",160,40,40,40,46,40,0,0};type[343]=-10;
guo[344]={"金涛杰","",160,40,40,40,46,40,0,0};type[344]=-2;
guo[345]={"金天宇","",160,40,40,40,46,40,0,0};type[345]=0;
guo[346]={"金恬","",160,40,40,40,46,40,0,0};type[346]=-4;
guo[347]={"金庭冉","",160,40,40,40,46,40,0,0};type[347]=-4;
guo[348]={"金薇薇","",160,40,40,40,46,40,0,0};type[348]=-4;
guo[349]={"金骁杨","",160,40,40,40,46,40,0,0};type[349]=-12;
guo[350]={"金妍池","",160,40,40,40,46,40,0,0};type[350]=-13;
guo[351]={"金颜童","",160,40,40,40,46,40,0,0};type[351]=-4;
guo[352]={"金一丹","",160,40,40,40,46,40,0,0};type[352]=-14;
guo[353]={"金易文","",160,40,40,40,46,40,0,0};type[353]=-15;
guo[354]={"金轶嘉","",160,40,40,40,46,40,0,0};type[354]=-1;
guo[355]={"金逸宁","",160,40,40,40,46,40,0,0};type[355]=-8;
guo[356]={"金垠锜","",160,40,40,40,46,40,0,0};type[356]=-9;
guo[357]={"金英杰","",160,40,40,40,46,40,0,0};type[357]=-2;
guo[358]={"金宇杰","",160,40,40,40,46,40,0,0};type[358]=-12;
guo[359]={"金雨丰","",160,40,40,40,46,40,0,0};type[359]=-16;
guo[360]={"金雨卡","",160,40,40,40,46,40,0,0};type[360]=-4;
guo[361]={"金玉婷","",160,40,40,40,46,40,0,0};type[361]=-13;
guo[362]={"金裕杰","",160,40,40,40,46,40,0,0};type[362]=-15;
guo[363]={"金峥","",160,40,40,40,46,40,0,0};type[363]=-1;
guo[364]={"金政扬","",160,40,40,40,46,40,0,0};type[364]=-12;
guo[365]={"晋诗羽","",160,40,40,40,46,40,0,0};type[365]=-13;
guo[366]={"靳炜杰","",160,40,40,40,46,40,0,0};type[366]=-8;
guo[367]={"孔佳慧","",160,40,40,40,46,40,0,0};type[367]=-14;
guo[368]={"孔君","",240,60,60,60,61,60,0,0};type[368]=15;
guo[369]={"孔利军","",240,60,60,60,61,60,0,0};type[369]=18;
guo[370]={"孔祥新","",240,60,60,60,61,60,0,0};type[370]=9;
guo[371]={"劳心仪","",160,40,40,40,46,40,0,0};type[371]=-4;
guo[372]={"李超奇","",160,40,40,40,46,40,0,0};type[372]=-7;
guo[373]={"李海东","",160,40,40,40,46,40,0,0};type[373]=-10;
guo[374]={"李豪森","",160,40,40,40,46,40,0,0};type[374]=-3;
guo[375]={"李浩腾","",160,40,40,40,46,40,0,0};type[375]=-7;
guo[376]={"李佳宁","",160,40,40,40,46,40,0,0};type[376]=-14;
guo[377]={"李家成","",160,40,40,40,46,40,0,0};type[377]=-10;
guo[378]={"李京","",160,40,40,40,46,40,0,0};type[378]=-6;
guo[379]={"李旼晖","",160,40,40,40,46,40,0,0};type[379]=-2;
guo[380]={"李睿","",160,40,40,40,46,40,0,0};type[380]=-4;
guo[381]={"李睿城","",160,40,40,40,46,40,0,0};type[381]=-10;
guo[382]={"李若男","",160,40,40,40,46,40,0,0};type[382]=-7;
guo[383]={"李恬儿","",160,40,40,40,46,40,0,0};type[383]=-8;
guo[384]={"李想","",160,40,40,40,46,40,0,0};type[384]=-15;
guo[385]={"李笑笑","",160,40,40,40,46,40,0,0};type[385]=-6;
guo[386]={"李轩昊","",160,40,40,40,46,40,0,0};type[386]=-7;
guo[387]={"李益开","",160,40,40,40,46,40,0,0};type[387]=-11;
guo[388]={"李宇楠","",160,40,40,40,46,40,0,0};type[388]=-2;
guo[389]={"李雨桐","",160,40,40,40,46,40,0,0};type[389]=-8;
guo[390]={"李雨欣","",160,40,40,40,46,40,0,0};type[390]=-5;
guo[391]={"李岳信","",240,60,60,60,61,60,0,0};type[391]=3;
guo[392]={"李浙湘","",160,40,40,40,46,40,0,0};type[392]=-1;
guo[393]={"李卓霖","",160,40,40,40,46,40,0,0};type[393]=-4;
guo[394]={"厉文浩","",160,40,40,40,46,40,0,0};type[394]=-13;
guo[395]={"郦东昊","",160,40,40,40,46,40,0,0};type[395]=-13;
guo[396]={"郦羽杰","",160,40,40,40,46,40,0,0};type[396]=-5;
guo[397]={"郦章华","",240,60,60,60,61,60,0,0};type[397]=9;
guo[398]={"郦秩","",160,40,40,40,46,40,0,0};type[398]=-13;
guo[399]={"廖烨","",240,60,60,60,61,60,0,0};type[399]=15;
guo[400]={"林佳倩","",160,40,40,40,46,40,0,0};type[400]=-9;
guo[401]={"林萍华","",340,85,85,85,91,85,0,0};type[401]=19;
guo[402]={"林雪旖","",160,40,40,40,46,40,0,0};type[402]=-6;
guo[403]={"林质彬","",160,40,40,40,46,40,0,0};type[403]=-11;
guo[404]={"凌栋钦","",160,40,40,40,46,40,0,0};type[404]=-13;
guo[405]={"凌佳欣","",160,40,40,40,46,40,0,0};type[405]=-4;
guo[406]={"凌晓锋","",240,60,60,60,61,60,0,0};type[406]=9;
guo[407]={"刘佳其","",160,40,40,40,46,40,0,0};type[407]=-11;
guo[408]={"刘军霞","",240,60,60,60,61,60,0,0};type[408]=8;
guo[409]={"刘美君","",160,40,40,40,46,40,0,0};type[409]=-10;
guo[410]={"刘明玉","",300,75,75,75,76,75,0,0};type[410]=19;
guo[411]={"刘淑芳","",240,60,60,60,61,60,0,0};type[411]=15;
guo[412]={"刘夏进","",331,82,82,82,91,85,0,0};type[412]=19;
guo[413]={"刘晓牛","",240,60,60,60,61,60,0,0};type[413]=9;
guo[414]={"刘星芸","",160,40,40,40,46,40,0,0};type[414]=-5;
guo[415]={"刘依兰","",160,40,40,40,46,40,0,0};type[415]=-1;
guo[416]={"刘怡青","",160,40,40,40,46,40,0,0};type[416]=-6;
guo[417]={"刘钰沣","",160,40,40,40,46,40,0,0};type[417]=-14;
guo[418]={"柳嘉仪","",160,40,40,40,46,40,0,0};type[418]=-13;
guo[419]={"娄珊珊","",160,40,40,40,46,40,0,0};type[419]=-10;
guo[420]={"娄世绎","",160,40,40,40,46,40,0,0};type[420]=-14;
guo[421]={"娄天一","",160,40,40,40,46,40,0,0};type[421]=-12;
guo[422]={"娄一凡","",160,40,40,40,46,40,0,0};type[422]=-16;
guo[423]={"楼晨","",160,40,40,40,46,40,0,0};type[423]=-5;
guo[424]={"楼家宁","",160,40,40,40,46,40,0,0};type[424]=-8;
guo[425]={"楼嘉滢","",160,40,40,40,46,40,0,0};type[425]=-5;
guo[426]={"楼开颜","",240,60,60,60,61,60,0,0};type[426]=13;
guo[427]={"楼立青","",240,60,60,60,61,60,0,0};type[427]=15;
guo[428]={"卢燎亚","",349,88,88,88,91,85,0,0};type[428]=20;
guo[429]={"卢卫红","",240,60,60,60,61,60,0,0};type[429]=12;
guo[430]={"卢易伽","",160,40,40,40,46,40,0,0};type[430]=-12;
guo[431]={"鲁豪然","",240,60,60,60,61,60,0,0};type[431]=16;
guo[432]={"鲁佳城","",160,40,40,40,46,40,0,0};type[432]=-9;
guo[433]={"鲁洁","",160,40,40,40,46,40,0,0};type[433]=-6;
guo[434]={"鲁炆杰","",160,40,40,40,46,40,0,0};type[434]=-9;
guo[435]={"鲁耀威","",160,40,40,40,46,40,0,0};type[435]=-2;
guo[436]={"鲁一晨","",160,40,40,40,46,40,0,0};type[436]=-7;
guo[437]={"鲁意","",160,40,40,40,46,40,0,0};type[437]=-1;
guo[438]={"鲁毅涛","",160,40,40,40,46,40,0,0};type[438]=-13;
guo[439]={"鲁雨成","",160,40,40,40,46,40,0,0};type[439]=-13;
guo[440]={"鲁煜恺","",160,40,40,40,46,40,0,0};type[440]=-14;
guo[441]={"陆涵颖","",160,40,40,40,46,40,0,0};type[441]=-4;
guo[442]={"陆浩天","",160,40,40,40,46,40,0,0};type[442]=-13;
guo[443]={"陆宇杰","",160,40,40,40,46,40,0,0};type[443]=-9;
guo[444]={"路孝萌","",160,40,40,40,46,40,0,0};type[444]=-12;
guo[445]={"栾俊宁","",160,40,40,40,46,40,0,0};type[445]=-8;
guo[446]={"罗晨浩","",160,40,40,40,46,40,0,0};type[446]=-7;
guo[447]={"罗江涛","",160,40,40,40,46,40,0,0};type[447]=-9;
guo[448]={"罗凯楠","",160,40,40,40,46,40,0,0};type[448]=-7;
guo[449]={"罗可典","",160,40,40,40,46,40,0,0};type[449]=-7;
guo[450]={"罗文颀","",160,40,40,40,46,40,0,0};type[450]=-16;
guo[451]={"罗卓亚","",160,40,40,40,46,40,0,0};type[451]=-5;
guo[452]={"骆惠新","",240,60,60,60,61,60,0,0};type[452]=16;
guo[453]={"吕康杰","",160,40,40,40,46,40,0,0};type[453]=-3;
guo[454]={"吕柳城","",160,40,40,40,46,40,0,0};type[454]=-1;
guo[455]={"吕润泽","",160,40,40,40,46,40,0,0};type[455]=-9;
guo[456]={"吕晓筱","",160,40,40,40,46,40,0,0};type[456]=-13;
guo[457]={"吕中宁","",160,40,40,40,46,40,0,0};type[457]=-16;
guo[458]={"马丹娜","",240,60,60,60,61,60,0,0};type[458]=8;
guo[459]={"马丹阳","",160,40,40,40,46,40,0,0};type[459]=-9;
guo[460]={"马宁敏","",160,40,40,40,46,40,0,0};type[460]=-7;
guo[461]={"马琦梦","",160,40,40,40,46,40,0,0};type[461]=-1;
guo[462]={"马书立","",160,40,40,40,46,40,0,0};type[462]=-11;
guo[463]={"马田瑜","",160,40,40,40,46,40,0,0};type[463]=-15;
guo[464]={"马钟欣","",160,40,40,40,46,40,0,0};type[464]=-5;
guo[465]={"马朱奕","",160,40,40,40,46,40,0,0};type[465]=-1;
guo[466]={"马作菁","",240,60,60,60,61,60,0,0};type[466]=2;
guo[467]={"毛伊颜","",160,40,40,40,46,40,0,0};type[467]=-7;
guo[468]={"孟德超","",240,60,60,60,61,60,0,0};type[468]=10;
guo[469]={"孟嘉政","",160,40,40,40,46,40,0,0};type[469]=-12;
guo[470]={"孟玲燕","",240,60,60,60,61,60,0,0};type[470]=14;
guo[471]={"孟琴音","",160,40,40,40,46,40,0,0};type[471]=-5;
guo[472]={"孟伟强","",240,60,60,60,61,60,0,0};type[472]=9;
guo[473]={"孟烨珂","",160,40,40,40,46,40,0,0};type[473]=-5;
guo[474]={"孟逸群","",160,40,40,40,46,40,0,0};type[474]=-7;
guo[475]={"孟子衿","",160,40,40,40,46,40,0,0};type[475]=-5;
guo[476]={"苗俊丰","",160,40,40,40,46,40,0,0};type[476]=-7;
guo[477]={"缪源一","",160,40,40,40,46,40,0,0};type[477]=-6;
guo[478]={"缪之恺","",160,40,40,40,46,40,0,0};type[478]=-15;
guo[479]={"牟思涵","",160,40,40,40,46,40,0,0};type[479]=-16;
guo[480]={"倪海森","",160,40,40,40,46,40,0,0};type[480]=-15;
guo[481]={"倪晗悦","",160,40,40,40,46,40,0,0};type[481]=-15;
guo[482]={"倪绮霞","",160,40,40,40,46,40,0,0};type[482]=-1;
guo[483]={"倪奕飞","",160,40,40,40,46,40,0,0};type[483]=-4;
guo[484]={"聂云","",210,50,50,60,46,50,0,0};type[484]=7;
guo[485]={"潘李靓","",160,40,40,40,46,40,0,0};type[485]=-4;
guo[486]={"潘林越","",160,40,40,40,46,40,0,0};type[486]=-15;
guo[487]={"潘思懿","",160,40,40,40,46,40,0,0};type[487]=-5;
guo[488]={"潘婷婷","",160,40,40,40,46,40,0,0};type[488]=-14;
guo[489]={"潘雅婷","",160,40,40,40,46,40,0,0};type[489]=-5;
guo[490]={"潘瑶婷","",160,40,40,40,46,40,0,0};type[490]=-4;
guo[491]={"潘雨婷","",160,40,40,40,46,40,0,0};type[491]=-9;
guo[492]={"潘桢妍","",160,40,40,40,46,40,0,0};type[492]=-5;
guo[493]={"潘祝君","",160,40,40,40,46,40,0,0};type[493]=-10;
guo[494]={"庞琳杰","",160,40,40,40,46,40,0,0};type[494]=-13;
guo[495]={"庞亚轩","",160,40,40,40,46,40,0,0};type[495]=-5;
guo[496]={"彭爱波","",240,60,60,60,61,60,0,0};type[496]=17;
guo[497]={"彭荣丽","",160,40,40,40,46,40,0,0};type[497]=-12;
guo[498]={"平晨昊","",160,40,40,40,46,40,0,0};type[498]=-3;
guo[499]={"平建树","",240,60,60,60,61,60,0,0};type[499]=5;
guo[500]={"平幸卉","",160,40,40,40,46,40,0,0};type[500]=-1;
guo[501]={"戚天怡","",160,40,40,40,46,40,0,0};type[501]=-7;
guo[502]={"戚予立","",160,40,40,40,46,40,0,0};type[502]=-10;
guo[503]={"祁丁涛","",160,40,40,40,46,40,0,0};type[503]=-5;
guo[504]={"祁浩","",160,40,40,40,46,40,0,0};type[504]=-7;
guo[505]={"祁开祺","",160,40,40,40,46,40,0,0};type[505]=-9;
guo[506]={"祁倩","",210,50,50,60,46,50,0,0};type[506]=1;
guo[507]={"祁雪丹","",160,40,40,40,46,40,0,0};type[507]=-14;
guo[508]={"钱晨炼","",160,40,40,40,46,40,0,0};type[508]=-11;
guo[509]={"钱虹燕","",240,60,60,60,61,60,0,0};type[509]=15;
guo[510]={"钱家瑜","",160,40,40,40,46,40,0,0};type[510]=-2;
guo[511]={"钱庆来","",160,40,40,40,46,40,0,0};type[511]=-6;
guo[512]={"钱胜男","",160,40,40,40,46,40,0,0};type[512]=-11;
guo[513]={"钱书仰","",160,40,40,40,46,40,0,0};type[513]=-16;
guo[514]={"钱奕丞","",160,40,40,40,46,40,0,0};type[514]=-1;
guo[515]={"秦佳怡","",160,40,40,40,46,40,0,0};type[515]=-10;
guo[516]={"秦黎","",240,60,60,60,61,60,0,0};type[516]=13;
guo[517]={"邱静娥","",240,60,60,60,61,60,0,0};type[517]=17;
guo[518]={"邱庆豪","",160,40,40,40,46,40,0,0};type[518]=-12;
guo[519]={"邱仕豪","",160,40,40,40,46,40,0,0};type[519]=-1;
guo[520]={"裘洪萍","",240,60,60,60,61,60,0,0};type[520]=15;
guo[521]={"裘剑飞","",160,40,40,40,46,40,0,0};type[521]=-9;
guo[522]={"裘思远","",160,40,40,40,46,40,0,0};type[522]=-5;
guo[523]={"裘天绮","",160,40,40,40,46,40,0,0};type[523]=-4;
guo[524]={"裘哲","",160,40,40,40,46,40,0,0};type[524]=-9;
guo[525]={"裘真","",160,40,40,40,46,40,0,0};type[525]=-6;
guo[526]={"裘峥","",160,40,40,40,46,40,0,0};type[526]=-11;
guo[527]={"任皓炜","",160,40,40,40,46,40,0,0};type[527]=-2;
guo[528]={"任和","",160,40,40,40,46,40,0,0};type[528]=-13;
guo[529]={"任君彬","",160,40,40,40,46,40,0,0};type[529]=-3;
guo[530]={"任奕遒","",160,40,40,40,46,40,0,0};type[530]=-1;
guo[531]={"任哲文","",160,40,40,40,46,40,0,0};type[531]=-11;
guo[532]={"戎辉","",160,40,40,40,46,40,0,0};type[532]=-9;
guo[533]={"阮国华","",240,60,60,60,61,60,0,0};type[533]=10;
guo[534]={"阮嘉烨","",160,40,40,40,46,40,0,0};type[534]=-14;
guo[535]={"阮丽艳","",160,40,40,40,46,40,0,0};type[535]=-12;
guo[536]={"阮敏捷","",160,40,40,40,46,40,0,0};type[536]=-7;
guo[537]={"阮文锋","",160,40,40,40,46,40,0,0};type[537]=-2;
guo[538]={"阮赵可","",160,40,40,40,46,40,0,0};type[538]=-5;
guo[539]={"桑美娟","",240,60,60,60,61,60,0,0};type[539]=15;
guo[540]={"商浚哲","",160,40,40,40,46,40,0,0};type[540]=-12;
guo[541]={"商书畅","",160,40,40,40,46,40,0,0};type[541]=-9;
guo[542]={"邵丹菲","",160,40,40,40,46,40,0,0};type[542]=-12;
guo[543]={"邵无为","",160,40,40,40,46,40,0,0};type[543]=-13;
guo[544]={"邵张彬","",240,60,60,60,61,60,0,0};type[544]=5;
guo[545]={"沈超华","",240,60,60,60,61,60,0,0};type[545]=3;
guo[546]={"沈晨阳","",160,40,40,40,46,40,0,0};type[546]=-13;
guo[547]={"沈初见","",286,72,72,72,76,70,0,0};type[547]=8;
guo[548]={"沈栋啸","",240,60,60,60,61,60,0,0};type[548]=9;
guo[549]={"沈贺蕾","",160,40,40,40,46,40,0,0};type[549]=-5;
guo[550]={"沈佳楠","",160,40,40,40,46,40,0,0};type[550]=-6;
guo[551]={"沈佳雯","",160,40,40,40,46,40,0,0};type[551]=-14;
guo[552]={"沈嘉怡","",160,40,40,40,46,40,0,0};type[552]=-5;
guo[553]={"沈剑蕾","",240,60,60,60,61,60,0,0};type[553]=15;
guo[554]={"沈静怡","",160,40,40,40,46,40,0,0};type[554]=-1;
guo[555]={"沈浚哲","",160,40,40,40,46,40,0,0};type[555]=-13;
guo[556]={"沈敏杰","",160,40,40,40,46,40,0,0};type[556]=-10;
guo[557]={"沈秦越","",160,40,40,40,46,40,0,0};type[557]=0;
guo[558]={"沈姝曼","",160,40,40,40,46,40,0,0};type[558]=-5;
guo[559]={"沈淑怡","",160,40,40,40,46,40,0,0};type[559]=-4;
guo[560]={"沈雯怡","",160,40,40,40,46,40,0,0};type[560]=-14;
guo[561]={"沈祥土","",300,75,75,75,76,75,0,0};type[561]=19;
guo[562]={"沈欣琪","",160,40,40,40,46,40,0,0};type[562]=-4;
guo[563]={"沈序戎","",160,40,40,40,46,40,0,0};type[563]=-10;
guo[564]={"沈洋铭","",240,60,60,60,61,60,0,0};type[564]=3;
guo[565]={"沈怡然","",160,40,40,40,46,40,0,0};type[565]=0;
guo[566]={"沈奕楠","",160,40,40,40,46,40,0,0};type[566]=-8;
guo[567]={"沈溢鼎","",160,40,40,40,46,40,0,0};type[567]=-3;
guo[568]={"沈熠","",160,40,40,40,46,40,0,0};type[568]=-5;
guo[569]={"沈宇昊","",160,40,40,40,46,40,0,0};type[569]=-4;
guo[570]={"沈卓琼","",160,40,40,40,46,40,0,0};type[570]=-16;
guo[571]={"盛婷婷","",240,60,60,60,61,60,0,0};type[571]=15;
guo[572]={"施卡祥","",240,60,60,60,61,60,0,0};type[572]=13;
guo[573]={"施钦阗","",160,40,40,40,46,40,0,0};type[573]=-4;
guo[574]={"施笑程","",300,75,75,75,76,75,0,0};type[574]=3;
guo[575]={"施熠辉","",160,40,40,40,46,40,0,0};type[575]=-12;
guo[576]={"施征宇","",160,40,40,40,46,40,0,0};type[576]=-16;
guo[577]={"石谷颖","",240,60,60,60,61,60,0,0};type[577]=18;
guo[578]={"石沁","",160,40,40,40,46,40,0,0};type[578]=-5;
guo[579]={"石震巍","",160,40,40,40,46,40,0,0};type[579]=-16;
guo[580]={"史淑琦","",160,40,40,40,46,40,0,0};type[580]=-6;
guo[581]={"史伟芳","",210,50,50,60,46,50,0,0};type[581]=7;
guo[582]={"史永浩","",160,40,40,40,46,40,0,0};type[582]=-7;
guo[583]={"寿家跃","",160,40,40,40,46,40,0,0};type[583]=-10;
guo[584]={"寿倪正","",160,40,40,40,46,40,0,0};type[584]=-5;
guo[585]={"寿绮雯","",160,40,40,40,46,40,0,0};type[585]=-14;
guo[586]={"寿霆丰","",160,40,40,40,46,40,0,0};type[586]=-11;
guo[587]={"寿洋洋","",160,40,40,40,46,40,0,0};type[587]=-8;
guo[588]={"寿之星","",160,40,40,40,46,40,0,0};type[588]=-12;
guo[589]={"舒凤","",240,60,60,60,61,60,0,0};type[589]=6;
guo[590]={"水丹枫","",160,40,40,40,46,40,0,0};type[590]=-6;
guo[591]={"水洋栋","",160,40,40,40,46,40,0,0};type[591]=-7;
guo[592]={"宋晨","",160,40,40,40,46,40,0,0};type[592]=-16;
guo[593]={"宋弘韬","",240,60,60,60,61,60,0,0};type[593]=18;
guo[594]={"宋嘉怡","",160,40,40,40,46,40,0,0};type[594]=-15;
guo[595]={"宋婕","",160,40,40,40,46,40,0,0};type[595]=-11;
guo[596]={"宋璟涵","",160,40,40,40,46,40,0,0};type[596]=-8;
guo[597]={"宋开程","",160,40,40,40,46,40,0,0};type[597]=-16;
guo[598]={"宋琦","",160,40,40,40,46,40,0,0};type[598]=-14;
guo[599]={"宋清哲","",160,40,40,40,46,40,0,0};type[599]=-3;
guo[600]={"宋沙清","",160,40,40,40,46,40,0,0};type[600]=-12;
guo[601]={"宋世煜","",160,40,40,40,46,40,0,0};type[601]=-12;
guo[602]={"宋雯睿","",160,40,40,40,46,40,0,0};type[602]=-5;
guo[603]={"宋妤恬","",160,40,40,40,46,40,0,0};type[603]=-6;
guo[604]={"宋芷盈","",160,40,40,40,46,40,0,0};type[604]=-15;
guo[605]={"苏鹏涛","",160,40,40,40,46,40,0,0};type[605]=-11;
guo[606]={"苏卫军","",291,72,72,72,76,75,0,0};type[606]=9;
guo[607]={"苏修远","",160,40,40,40,46,40,0,0};type[607]=-11;
guo[608]={"孙博波","",160,40,40,40,46,40,0,0};type[608]=-8;
guo[609]={"孙丹娜","",160,40,40,40,46,40,0,0};type[609]=-13;
guo[610]={"孙丁宜","",160,40,40,40,46,40,0,0};type[610]=-8;
guo[611]={"孙恩凯","",160,40,40,40,46,40,0,0};type[611]=-6;
guo[612]={"孙飞扬","",160,40,40,40,46,40,0,0};type[612]=-3;
guo[613]={"孙军耀","",160,40,40,40,46,40,0,0};type[613]=-12;
guo[614]={"孙宁睿","",160,40,40,40,46,40,0,0};type[614]=0;
guo[615]={"孙麒婷","",160,40,40,40,46,40,0,0};type[615]=-13;
guo[616]={"孙乾程","",160,40,40,40,46,40,0,0};type[616]=-16;
guo[617]={"孙洋","",160,40,40,40,46,40,0,0};type[617]=-2;
guo[618]={"孙以然","",160,40,40,40,46,40,0,0};type[618]=-2;
guo[619]={"孙宇晴","",160,40,40,40,46,40,0,0};type[619]=-12;
guo[620]={"孙正男","",160,40,40,40,46,40,0,0};type[620]=-9;
guo[621]={"孙卓怡","",160,40,40,40,46,40,0,0};type[621]=-9;
guo[622]={"谭跃洲","",160,40,40,40,46,40,0,0};type[622]=-6;
guo[623]={"汤世俊","",160,40,40,40,46,40,0,0};type[623]=-3;
guo[624]={"汤喻淇","",160,40,40,40,46,40,0,0};type[624]=-14;
guo[625]={"唐海燕","",240,60,60,60,61,60,0,0};type[625]=16;
guo[626]={"唐钰莹","",160,40,40,40,46,40,0,0};type[626]=-1;
guo[627]={"陶晨阳","",160,40,40,40,46,40,0,0};type[627]=-3;
guo[628]={"陶晨耀","",160,40,40,40,46,40,0,0};type[628]=-4;
guo[629]={"陶佳卉","",240,60,60,60,61,60,0,0};type[629]=8;
guo[630]={"陶金奇","",160,40,40,40,46,40,0,0};type[630]=-15;
guo[631]={"陶婷婷","",160,40,40,40,46,40,0,0};type[631]=-8;
guo[632]={"陶忻妤","",160,40,40,40,46,40,0,0};type[632]=-2;
guo[633]={"陶欣怡","",160,40,40,40,46,40,0,0};type[633]=-6;
guo[634]={"陶馨瑜","",160,40,40,40,46,40,0,0};type[634]=-4;
guo[635]={"陶妍祺","",160,40,40,40,46,40,0,0};type[635]=-14;
guo[636]={"陶叶雨","",160,40,40,40,46,40,0,0};type[636]=-5;
guo[637]={"陶逸婷","",160,40,40,40,46,40,0,0};type[637]=-8;
guo[638]={"陶喆煊","",160,40,40,40,46,40,0,0};type[638]=-6;
guo[639]={"陶中天","",160,40,40,40,46,40,0,0};type[639]=-15;
guo[640]={"滕铱珂","",160,40,40,40,46,40,0,0};type[640]=-16;
guo[641]={"田婧","",160,40,40,40,46,40,0,0};type[641]=-16;
guo[642]={"田哲男","",160,40,40,40,46,40,0,0};type[642]=-6;
guo[643]={"田振楠","",160,40,40,40,46,40,0,0};type[643]=-10;
guo[644]={"童均浩","",160,40,40,40,46,40,0,0};type[644]=-9;
guo[645]={"童开翼","",160,40,40,40,46,40,0,0};type[645]=-4;
guo[646]={"童莉芳","",240,60,60,60,61,60,0,0};type[646]=6;
guo[647]={"童烁岚","",160,40,40,40,46,40,0,0};type[647]=-2;
guo[648]={"屠磊","",160,40,40,40,46,40,0,0};type[648]=-2;
guo[649]={"屠蕊林","",160,40,40,40,46,40,0,0};type[649]=-8;
guo[650]={"屠澍田","",160,40,40,40,46,40,0,0};type[650]=-16;
guo[651]={"屠天波","",160,40,40,40,46,40,0,0};type[651]=-15;
guo[652]={"屠天航","",160,40,40,40,46,40,0,0};type[652]=-6;
guo[653]={"屠翌","",160,40,40,40,46,40,0,0};type[653]=-14;
guo[654]={"汪陈帅","",240,60,60,60,61,60,0,0};type[654]=18;
guo[655]={"汪书楠","",160,40,40,40,46,40,0,0};type[655]=-5;
guo[656]={"汪垚程","",160,40,40,40,46,40,0,0};type[656]=-13;
guo[657]={"王安煜","",160,40,40,40,46,40,0,0};type[657]=-10;
guo[658]={"王柏根","",240,60,60,60,61,60,0,0};type[658]=1;
guo[659]={"王彬","",160,40,40,40,46,40,0,0};type[659]=-2;
guo[660]={"王斌杰","",160,40,40,40,46,40,0,0};type[660]=-11;
guo[661]={"王冰洁","",240,60,60,60,61,60,0,0};type[661]=10;
guo[662]={"王炳祥","",210,50,50,60,46,50,0,0};type[662]=1;
guo[663]={"王辰昊","",160,40,40,40,46,40,0,0};type[663]=-3;
guo[664]={"王法新","",240,60,60,60,61,60,0,0};type[664]=5;
guo[665]={"王芳","",240,60,60,60,61,60,0,0};type[665]=15;
guo[666]={"王芳芳","",240,60,60,60,61,60,0,0};type[666]=17;
guo[667]={"王海燕","",280,70,70,70,76,70,0,0};type[667]=6;
guo[668]={"王含冰","",160,40,40,40,46,40,0,0};type[668]=-1;
guo[669]={"王韩杰","",160,40,40,40,46,40,0,0};type[669]=-16;
guo[670]={"王昊石","",160,40,40,40,46,40,0,0};type[670]=-6;
guo[671]={"王浩宇","",160,40,40,40,46,40,0,0};type[671]=-15;
guo[672]={"王赫铭","",160,40,40,40,46,40,0,0};type[672]=-8;
guo[673]={"王鸿宇","",160,40,40,40,46,40,0,0};type[673]=-3;
guo[674]={"王华磊","",160,40,40,40,46,40,0,0};type[674]=-1;
guo[675]={"王济源","",160,40,40,40,46,40,0,0};type[675]=-4;
guo[676]={"王佳丽","",160,40,40,40,46,40,0,0};type[676]=-1;
guo[677]={"王佳沁","",160,40,40,40,46,40,0,0};type[677]=-8;
guo[678]={"王佳熠","",160,40,40,40,46,40,0,0};type[678]=-6;
guo[679]={"王嘉豪","",160,40,40,40,46,40,0,0};type[679]=-8;
guo[680]={"王杰涛","",160,40,40,40,46,40,0,0};type[680]=-10;
guo[681]={"王洁","",240,60,60,60,61,60,0,0};type[681]=16;
guo[682]={"王晶晶","",300,75,75,75,76,75,0,0};type[682]=19;
guo[683]={"王俊昊","",160,40,40,40,46,40,0,0};type[683]=-12;
guo[684]={"王恺雨","",160,40,40,40,46,40,0,0};type[684]=-15;
guo[685]={"王柯亭","",160,40,40,40,46,40,0,0};type[685]=-7;
guo[686]={"王可","",160,40,40,40,46,40,0,0};type[686]=-15;
guo[687]={"王立凡","",160,40,40,40,46,40,0,0};type[687]=-8;
guo[688]={"王亮捷","",160,40,40,40,46,40,0,0};type[688]=-16;
guo[689]={"王林龙","",160,40,40,40,46,40,0,0};type[689]=-4;
guo[690]={"王勉","",160,40,40,40,46,40,0,0};type[690]=-8;
guo[691]={"王宁","",240,60,60,60,61,60,0,0};type[691]=6;
guo[692]={"王佩金","",240,60,60,60,61,60,0,0};type[692]=18;
guo[693]={"王佩婧","",160,40,40,40,46,40,0,0};type[693]=-6;
guo[694]={"王萍","",160,40,40,40,46,40,0,0};type[694]=-2;
guo[695]={"王奇燕","",160,40,40,40,46,40,0,0};type[695]=-1;
guo[696]={"王琦","",160,40,40,40,46,40,0,0};type[696]=-4;
guo[697]={"王青","",210,50,50,60,46,50,0,0};type[697]=7;
guo[698]={"王青怡","",160,40,40,40,46,40,0,0};type[698]=-15;
guo[699]={"王琼娜","",240,60,60,60,61,60,0,0};type[699]=10;
guo[700]={"王润叶","",160,40,40,40,46,40,0,0};type[700]=-5;
guo[701]={"王姗姗","",240,60,60,60,61,60,0,0};type[701]=5;
guo[702]={"王沈烨","",160,40,40,40,46,40,0,0};type[702]=-3;
guo[703]={"王司豪","",160,40,40,40,46,40,0,0};type[703]=-16;
guo[704]={"王思妍","",160,40,40,40,46,40,0,0};type[704]=-12;
guo[705]={"王天乐","",160,40,40,40,46,40,0,0};type[705]=-10;
guo[706]={"王天耀","",160,40,40,40,46,40,0,0};type[706]=-7;
guo[707]={"王维","",240,60,60,60,61,60,0,0};type[707]=15;
guo[708]={"王炜荣","",240,60,60,60,61,60,0,0};type[708]=3;
guo[709]={"王晓亮","",160,40,40,40,46,40,0,0};type[709]=-13;
guo[710]={"王晓哲","",160,40,40,40,46,40,0,0};type[710]=-15;
guo[711]={"王新东","",240,60,60,60,61,60,0,0};type[711]=16;
guo[712]={"王新璐","",240,60,60,60,61,60,0,0};type[712]=16;
guo[713]={"王馨露","",160,40,40,40,46,40,0,0};type[713]=-8;
guo[714]={"王轩宇","",160,40,40,40,46,40,0,0};type[714]=-11;
guo[715]={"王学文","",240,60,60,60,61,60,0,0};type[715]=3;
guo[716]={"王彦森","",160,40,40,40,46,40,0,0};type[716]=-5;
guo[717]={"王燕","",286,72,72,72,76,70,0,0};type[717]=2;
guo[718]={"王烨","",160,40,40,40,46,40,0,0};type[718]=-14;
guo[719]={"王一行","",240,60,60,60,61,60,0,0};type[719]=9;
guo[720]={"王一择","",160,40,40,40,46,40,0,0};type[720]=-11;
guo[721]={"王怡能","",160,40,40,40,46,40,0,0};type[721]=-13;
guo[722]={"王弋戈","",160,40,40,40,46,40,0,0};type[722]=-11;
guo[723]={"王亿铮","",160,40,40,40,46,40,0,0};type[723]=-2;
guo[724]={"王艺陶","",160,40,40,40,46,40,0,0};type[724]=-5;
guo[725]={"王毅扬","",160,40,40,40,46,40,0,0};type[725]=0;
guo[726]={"王懿诺","",160,40,40,40,46,40,0,0};type[726]=-15;
guo[727]={"王颖杰","",160,40,40,40,46,40,0,0};type[727]=-11;
guo[728]={"王优","",160,40,40,40,46,40,0,0};type[728]=-12;
guo[729]={"王幼青","",210,50,50,60,46,50,0,0};type[729]=1;
guo[730]={"王余同","",160,40,40,40,46,40,0,0};type[730]=-3;
guo[731]={"王宇","",160,40,40,40,46,40,0,0};type[731]=-16;
guo[732]={"王宇杰","",160,40,40,40,46,40,0,0};type[732]=-13;
guo[733]={"王宇龙","",160,40,40,40,46,40,0,0};type[733]=-10;
guo[734]={"王宇烜","",160,40,40,40,46,40,0,0};type[734]=-13;
guo[735]={"王雨辰","",160,40,40,40,46,40,0,0};type[735]=-11;
guo[736]={"王雨妮","",160,40,40,40,46,40,0,0};type[736]=-6;
guo[737]={"王雨萱","",160,40,40,40,46,40,0,0};type[737]=-12;
guo[738]={"王玉宇","",240,60,60,60,61,60,0,0};type[738]=15;
guo[739]={"王渊龙","",160,40,40,40,46,40,0,0};type[739]=-11;
guo[740]={"王月","",240,60,60,60,61,60,0,0};type[740]=2;
guo[741]={"王月琴","",300,75,75,75,76,75,0,0};type[741]=16;
guo[742]={"王泽城","",160,40,40,40,46,40,0,0};type[742]=-15;
guo[743]={"王哲","",160,40,40,40,46,40,0,0};type[743]=-7;
guo[744]={"王政韬","",160,40,40,40,46,40,0,0};type[744]=-11;
guo[745]={"王卓炜","",160,40,40,40,46,40,0,0};type[745]=-11;
guo[746]={"王子习","",160,40,40,40,46,40,0,0};type[746]=-10;
guo[747]={"王子越","",160,40,40,40,46,40,0,0};type[747]=0;
guo[748]={"危方梦洁","",160,40,40,40,46,40,0,0};type[748]=-7;
guo[749]={"韦澳蕾","",160,40,40,40,46,40,0,0};type[749]=-12;
guo[750]={"尉宸浩","",160,40,40,40,46,40,0,0};type[750]=-5;
guo[751]={"尉怡婷","",160,40,40,40,46,40,0,0};type[751]=-12;
guo[752]={"尉子仪","",160,40,40,40,46,40,0,0};type[752]=-10;
guo[753]={"魏杲","",210,50,50,60,46,50,0,0};type[753]=1;
guo[754]={"魏一磊","",160,40,40,40,46,40,0,0};type[754]=-16;
guo[755]={"翁凌洁","",160,40,40,40,46,40,0,0};type[755]=-8;
guo[756]={"翁鹏飞","",240,60,60,60,61,60,0,0};type[756]=13;
guo[757]={"沃睿萱","",160,40,40,40,46,40,0,0};type[757]=-6;
guo[758]={"邬依莉","",160,40,40,40,46,40,0,0};type[758]=-8;
guo[759]={"吴晨光","",160,40,40,40,46,40,0,0};type[759]=-16;
guo[760]={"吴迪文","",160,40,40,40,46,40,0,0};type[760]=-4;
guo[761]={"吴丰威","",160,40,40,40,46,40,0,0};type[761]=-1;
guo[762]={"吴国年","",210,50,50,60,46,50,0,0};type[762]=1;
guo[763]={"吴函咨","",160,40,40,40,46,40,0,0};type[763]=-8;
guo[764]={"吴涵","",160,40,40,40,46,40,0,0};type[764]=-11;
guo[765]={"吴瀚琦","",160,40,40,40,46,40,0,0};type[765]=-7;
guo[766]={"吴红婕","",160,40,40,40,46,40,0,0};type[766]=-1;
guo[767]={"吴佳楠","",160,40,40,40,46,40,0,0};type[767]=-7;
guo[768]={"吴皆宁","",160,40,40,40,46,40,0,0};type[768]=-14;
guo[769]={"吴津琪","",160,40,40,40,46,40,0,0};type[769]=-9;
guo[770]={"吴军芳","",240,60,60,60,61,60,0,0};type[770]=4;
guo[771]={"吴俊毅","",160,40,40,40,46,40,0,0};type[771]=-11;
guo[772]={"吴丽娟","",240,60,60,60,61,60,0,0};type[772]=10;
guo[773]={"吴旻","",160,40,40,40,46,40,0,0};type[773]=-16;
guo[774]={"吴苏颖","",160,40,40,40,46,40,0,0};type[774]=-1;
guo[775]={"吴威特","",160,40,40,40,46,40,0,0};type[775]=-6;
guo[776]={"吴巍巍","",240,60,60,60,61,60,0,0};type[776]=16;
guo[777]={"吴昕仪","",160,40,40,40,46,40,0,0};type[777]=-8;
guo[778]={"吴烨超","",160,40,40,40,46,40,0,0};type[778]=-1;
guo[779]={"吴一舟","",160,40,40,40,46,40,0,0};type[779]=-6;
guo[780]={"吴妤祺","",160,40,40,40,46,40,0,0};type[780]=-5;
guo[781]={"吴泽棋","",160,40,40,40,46,40,0,0};type[781]=-7;
guo[782]={"夏家乐","",160,40,40,40,46,40,0,0};type[782]=-2;
guo[783]={"夏敏茜","",160,40,40,40,46,40,0,0};type[783]=-12;
guo[784]={"夏青莲","",160,40,40,40,46,40,0,0};type[784]=-6;
guo[785]={"夏帅波","",240,60,60,60,61,60,0,0};type[785]=16;
guo[786]={"夏文珏","",160,40,40,40,46,40,0,0};type[786]=-10;
guo[787]={"夏翊哲","",160,40,40,40,46,40,0,0};type[787]=-10;
guo[788]={"夏泽楷","",160,40,40,40,46,40,0,0};type[788]=-3;
guo[789]={"相佳玥","",160,40,40,40,46,40,0,0};type[789]=-13;
guo[790]={"相卓伟","",160,40,40,40,46,40,0,0};type[790]=-13;
guo[791]={"肖潇","",160,40,40,40,46,40,0,0};type[791]=-14;
guo[792]={"肖洋溢","",160,40,40,40,46,40,0,0};type[792]=-11;
guo[793]={"肖宇煊","",160,40,40,40,46,40,0,0};type[793]=-15;
guo[794]={"谢超杰","",160,40,40,40,46,40,0,0};type[794]=-7;
guo[795]={"谢澹","",286,72,72,72,76,70,0,0};type[795]=16;
guo[796]={"谢汉寅","",160,40,40,40,46,40,0,0};type[796]=-12;
guo[797]={"谢鸿涛","",160,40,40,40,46,40,0,0};type[797]=-3;
guo[798]={"谢静超","",240,60,60,60,61,60,0,0};type[798]=15;
guo[799]={"谢君樑","",240,60,60,60,61,60,0,0};type[799]=3;
guo[800]={"谢乐其","",160,40,40,40,46,40,0,0};type[800]=-16;
guo[801]={"谢少杰","",160,40,40,40,46,40,0,0};type[801]=-1;
guo[802]={"谢世莹","",160,40,40,40,46,40,0,0};type[802]=-2;
guo[803]={"谢舒阳","",160,40,40,40,46,40,0,0};type[803]=-2;
guo[804]={"谢叶婷","",160,40,40,40,46,40,0,0};type[804]=-1;
guo[805]={"谢燚莹","",160,40,40,40,46,40,0,0};type[805]=-16;
guo[806]={"谢雨桐","",160,40,40,40,46,40,0,0};type[806]=-12;
guo[807]={"谢月明","",240,60,60,60,61,60,0,0};type[807]=15;
guo[808]={"谢泽栋","",160,40,40,40,46,40,0,0};type[808]=-9;
guo[809]={"邢楚涵","",160,40,40,40,46,40,0,0};type[809]=-5;
guo[810]={"邢婷","",240,60,60,60,61,60,0,0};type[810]=3;
guo[811]={"邢秀英","",240,60,60,60,61,60,0,0};type[811]=15;
guo[812]={"熊昊泉","",160,40,40,40,46,40,0,0};type[812]=-4;
guo[813]={"徐登科","",160,40,40,40,46,40,0,0};type[813]=-3;
guo[814]={"徐栋豪","",160,40,40,40,46,40,0,0};type[814]=-2;
guo[815]={"徐凤碧","",240,60,60,60,61,60,0,0};type[815]=18;
guo[816]={"徐晗墨","",160,40,40,40,46,40,0,0};type[816]=-3;
guo[817]={"徐涵纯","",160,40,40,40,46,40,0,0};type[817]=-12;
guo[818]={"徐浩然","",160,40,40,40,46,40,0,0};type[818]=-3;
guo[819]={"徐和杰","",160,40,40,40,46,40,0,0};type[819]=-7;
guo[820]={"徐弘仪","",160,40,40,40,46,40,0,0};type[820]=-6;
guo[821]={"徐佳浩","",160,40,40,40,46,40,0,0};type[821]=-3;
guo[822]={"徐佳薇","",160,40,40,40,46,40,0,0};type[822]=-7;
guo[823]={"徐家洛","",160,40,40,40,46,40,0,0};type[823]=-2;
guo[824]={"徐嘉婕","",160,40,40,40,46,40,0,0};type[824]=-8;
guo[825]={"徐嘉璐","",160,40,40,40,46,40,0,0};type[825]=-5;
guo[826]={"徐建光","",240,60,60,60,61,60,0,0};type[826]=11;
guo[827]={"徐柯洋","",160,40,40,40,46,40,0,0};type[827]=-7;
guo[828]={"徐科宇","",160,40,40,40,46,40,0,0};type[828]=-16;
guo[829]={"徐乐浓","",160,40,40,40,46,40,0,0};type[829]=-5;
guo[830]={"徐立旦","",240,60,60,60,61,60,0,0};type[830]=15;
guo[831]={"徐萍","",240,60,60,60,61,60,0,0};type[831]=9;
guo[832]={"徐倩雯","",160,40,40,40,46,40,0,0};type[832]=-12;
guo[833]={"徐如鸿","",160,40,40,40,46,40,0,0};type[833]=-5;
guo[834]={"徐童瑶","",160,40,40,40,46,40,0,0};type[834]=-1;
guo[835]={"徐雯","",240,60,60,60,61,60,0,0};type[835]=2;
guo[836]={"徐希彦","",160,40,40,40,46,40,0,0};type[836]=-10;
guo[837]={"徐潇彤","",160,40,40,40,46,40,0,0};type[837]=-16;
guo[838]={"徐小荃","",160,40,40,40,46,40,0,0};type[838]=-5;
guo[839]={"徐怡","",160,40,40,40,46,40,0,0};type[839]=-9;
guo[840]={"徐旖旎","",160,40,40,40,46,40,0,0};type[840]=-4;
guo[841]={"徐意然","",160,40,40,40,46,40,0,0};type[841]=-16;
guo[842]={"徐宇璐","",160,40,40,40,46,40,0,0};type[842]=-1;
guo[843]={"徐玉娇","",160,40,40,40,46,40,0,0};type[843]=-4;
guo[844]={"徐煜姣","",160,40,40,40,46,40,0,0};type[844]=-14;
guo[845]={"徐悦","",160,40,40,40,46,40,0,0};type[845]=-8;
guo[846]={"徐泽男","",160,40,40,40,46,40,0,0};type[846]=-7;
guo[847]={"徐哲淇","",160,40,40,40,46,40,0,0};type[847]=-8;
guo[848]={"许飞扬","",160,40,40,40,46,40,0,0};type[848]=-5;
guo[849]={"许佳烨","",160,40,40,40,46,40,0,0};type[849]=-13;
guo[850]={"许可沁","",160,40,40,40,46,40,0,0};type[850]=-2;
guo[851]={"许敏","",240,60,60,60,61,60,0,0};type[851]=16;
guo[852]={"许铭洋","",160,40,40,40,46,40,0,0};type[852]=-7;
guo[853]={"许诺","",160,40,40,40,46,40,0,0};type[853]=-4;
guo[854]={"许琪玫","",240,60,60,60,61,60,0,0};type[854]=17;
guo[855]={"许倩怡","",160,40,40,40,46,40,0,0};type[855]=-7;
guo[856]={"许书洋","",160,40,40,40,46,40,0,0};type[856]=-9;
guo[857]={"许婷","",240,60,60,60,61,60,0,0};type[857]=11;
guo[858]={"许亦雯","",160,40,40,40,46,40,0,0};type[858]=-4;
guo[859]={"许颖莹","",160,40,40,40,46,40,0,0};type[859]=-14;
guo[860]={"许雨冰","",160,40,40,40,46,40,0,0};type[860]=-12;
guo[861]={"许雨婷","",160,40,40,40,46,40,0,0};type[861]=-15;
guo[862]={"许泽坤","",160,40,40,40,46,40,0,0};type[862]=-10;
guo[863]={"宣桂林","",210,50,50,60,46,50,0,0};type[863]=7;
guo[864]={"宣晓洁","",160,40,40,40,46,40,0,0};type[864]=-1;
guo[865]={"薛鸽","",160,40,40,40,46,40,0,0};type[865]=-3;
guo[866]={"闫彦彦","",240,60,60,60,61,60,0,0};type[866]=17;
guo[867]={"严嘉程","",160,40,40,40,46,40,0,0};type[867]=-7;
guo[868]={"严聚卫","",160,40,40,40,46,40,0,0};type[868]=-13;
guo[869]={"严淇","",240,60,60,60,61,60,0,0};type[869]=8;
guo[870]={"严至简","",160,40,40,40,46,40,0,0};type[870]=-16;
guo[871]={"言利水","",240,60,60,60,61,60,0,0};type[871]=9;
guo[872]={"阳宽心","",160,40,40,40,46,40,0,0};type[872]=-8;
guo[873]={"阳绍龙","",160,40,40,40,46,40,0,0};type[873]=-9;
guo[874]={"杨辰霄","",160,40,40,40,46,40,0,0};type[874]=-7;
guo[875]={"杨大为","",240,60,60,60,61,60,0,0};type[875]=15;
guo[876]={"杨国平","",286,72,72,72,76,70,0,0};type[876]=13;
guo[877]={"杨国仁","",240,60,60,60,61,60,0,0};type[877]=9;
guo[878]={"杨红帆","",160,40,40,40,46,40,0,0};type[878]=-9;
guo[879]={"杨嘉敏","",160,40,40,40,46,40,0,0};type[879]=-6;
guo[880]={"杨晶晶","",240,60,60,60,61,60,0,0};type[880]=15;
guo[881]={"杨菊妃","",240,60,60,60,61,60,0,0};type[881]=15;
guo[882]={"杨恺","",160,40,40,40,46,40,0,0};type[882]=0;
guo[883]={"杨可宜","",160,40,40,40,46,40,0,0};type[883]=-10;
guo[884]={"杨佩琼","",348,86,86,86,91,90,0,0};type[884]=19;
guo[885]={"杨千仪","",160,40,40,40,46,40,0,0};type[885]=0;
guo[886]={"杨瑞敏","",240,60,60,60,61,60,0,0};type[886]=9;
guo[887]={"杨熊涛","",160,40,40,40,46,40,0,0};type[887]=-8;
guo[888]={"杨许靖","",160,40,40,40,46,40,0,0};type[888]=-7;
guo[889]={"杨嫣然","",160,40,40,40,46,40,0,0};type[889]=-11;
guo[890]={"杨炀","",240,60,60,60,61,60,0,0};type[890]=5;
guo[891]={"杨以恒","",160,40,40,40,46,40,0,0};type[891]=-8;
guo[892]={"杨怿驰","",160,40,40,40,46,40,0,0};type[892]=-9;
guo[893]={"杨奕帆","",160,40,40,40,46,40,0,0};type[893]=-6;
guo[894]={"杨羽琪","",160,40,40,40,46,40,0,0};type[894]=-4;
guo[895]={"杨臻超","",160,40,40,40,46,40,0,0};type[895]=-14;
guo[896]={"姚嘉程","",160,40,40,40,46,40,0,0};type[896]=-10;
guo[897]={"姚洁","",160,40,40,40,46,40,0,0};type[897]=-16;
guo[898]={"姚一旸","",160,40,40,40,46,40,0,0};type[898]=-3;
guo[899]={"叶冬","",160,40,40,40,46,40,0,0};type[899]=-7;
guo[900]={"叶晗晓","",160,40,40,40,46,40,0,0};type[900]=-14;
guo[901]={"叶鸿飞","",160,40,40,40,46,40,0,0};type[901]=-7;
guo[902]={"叶建红","",240,60,60,60,61,60,0,0};type[902]=16;
guo[903]={"叶建强","",240,60,60,60,61,60,0,0};type[903]=9;
guo[904]={"叶建映","",240,60,60,60,61,60,0,0};type[904]=15;
guo[905]={"叶灵","",160,40,40,40,46,40,0,0};type[905]=-13;
guo[906]={"叶佩莉","",286,72,72,72,76,70,0,0};type[906]=17;
guo[907]={"叶沁怡","",160,40,40,40,46,40,0,0};type[907]=-4;
guo[908]={"叶甜","",160,40,40,40,46,40,0,0};type[908]=-1;
guo[909]={"叶望尧","",340,85,85,85,91,85,0,0};type[909]=19;
guo[910]={"叶铮铮","",160,40,40,40,46,40,0,0};type[910]=-9;
guo[911]={"殷晗放","",160,40,40,40,46,40,0,0};type[911]=-11;
guo[912]={"尹嘉仪","",160,40,40,40,46,40,0,0};type[912]=-14;
guo[913]={"尹麒惠","",160,40,40,40,46,40,0,0};type[913]=0;
guo[914]={"尹诗怡","",160,40,40,40,46,40,0,0};type[914]=-8;
guo[915]={"应佳熠","",160,40,40,40,46,40,0,0};type[915]=-14;
guo[916]={"应筱菁","",160,40,40,40,46,40,0,0};type[916]=-1;
guo[917]={"应最时","",160,40,40,40,46,40,0,0};type[917]=-7;
guo[918]={"余晨阳","",160,40,40,40,46,40,0,0};type[918]=-13;
guo[919]={"余栋材","",240,60,60,60,61,60,0,0};type[919]=14;
guo[920]={"余红陆","",160,40,40,40,46,40,0,0};type[920]=-11;
guo[921]={"余佳成","",160,40,40,40,46,40,0,0};type[921]=-5;
guo[922]={"余婕","",160,40,40,40,46,40,0,0};type[922]=-6;
guo[923]={"余舒阳","",160,40,40,40,46,40,0,0};type[923]=-9;
guo[924]={"余喆","",160,40,40,40,46,40,0,0};type[924]=-9;
guo[925]={"余子兰","",240,60,60,60,61,60,0,0};type[925]=16;
guo[926]={"余子路","",160,40,40,40,46,40,0,0};type[926]=-13;
guo[927]={"俞宝根","",240,60,60,60,61,60,0,0};type[927]=8;
guo[928]={"俞晨亮","",160,40,40,40,46,40,0,0};type[928]=-13;
guo[929]={"俞飞菲","",160,40,40,40,46,40,0,0};type[929]=-1;
guo[930]={"俞浩楠","",160,40,40,40,46,40,0,0};type[930]=-2;
guo[931]={"俞鸿飞","",160,40,40,40,46,40,0,0};type[931]=-10;
guo[932]={"俞建种","",360,90,90,90,100,90,0,0};type[932]=20;
guo[933]={"俞景行","",160,40,40,40,46,40,0,0};type[933]=-12;
guo[934]={"俞俊杰","",160,40,40,40,46,40,0,0};type[934]=-7;
guo[935]={"俞快","",160,40,40,40,46,40,0,0};type[935]=-9;
guo[936]={"俞梁","",160,40,40,40,46,40,0,0};type[936]=-9;
guo[937]={"俞林","",160,40,40,40,46,40,0,0};type[937]=-13;
guo[938]={"俞苗锋","",240,60,60,60,61,60,0,0};type[938]=16;
guo[939]={"俞婷","",160,40,40,40,46,40,0,0};type[939]=-1;
guo[940]={"俞霞","",240,60,60,60,61,60,0,0};type[940]=3;
guo[941]={"俞笑晨","",240,60,60,60,61,60,0,0};type[941]=10;
guo[942]={"俞杨","",160,40,40,40,46,40,0,0};type[942]=-13;
guo[943]={"俞一凡","",240,60,60,60,61,60,0,0};type[943]=9;
guo[944]={"俞轶宸","",160,40,40,40,46,40,0,0};type[944]=-13;
guo[945]={"俞逸凡","",160,40,40,40,46,40,0,0};type[945]=-6;
guo[946]={"虞金龙","",286,72,72,72,76,70,0,0};type[946]=9;
guo[947]={"虞快","",160,40,40,40,46,40,0,0};type[947]=-10;
guo[948]={"喻天赐","",160,40,40,40,46,40,0,0};type[948]=-15;
guo[949]={"袁佳菲","",160,40,40,40,46,40,0,0};type[949]=-2;
guo[950]={"袁晟轶","",160,40,40,40,46,40,0,0};type[950]=-6;
guo[951]={"袁诗霞","",160,40,40,40,46,40,0,0};type[951]=-6;
guo[952]={"袁晓霞","",160,40,40,40,46,40,0,0};type[952]=-5;
guo[953]={"袁亚男","",240,60,60,60,61,60,0,0};type[953]=5;
guo[954]={"袁益瑜","",160,40,40,40,46,40,0,0};type[954]=-6;
guo[955]={"袁逸飞","",160,40,40,40,46,40,0,0};type[955]=-6;
guo[956]={"詹潇潇","",160,40,40,40,46,40,0,0};type[956]=-7;
guo[957]={"詹致豪","",160,40,40,40,46,40,0,0};type[957]=-13;
guo[958]={"张超","",240,60,60,60,61,60,0,0};type[958]=2;
guo[959]={"张楚林","",160,40,40,40,46,40,0,0};type[959]=-9;
guo[960]={"张春雨","",160,40,40,40,46,40,0,0};type[960]=-3;
guo[961]={"张叠","",286,72,72,72,76,70,0,0};type[961]=5;
guo[962]={"张帆","",240,60,60,60,61,60,0,0};type[962]=4;
guo[963]={"张飞跃","",160,40,40,40,46,40,0,0};type[963]=-8;
guo[964]={"张傅斌","",160,40,40,40,46,40,0,0};type[964]=-2;
guo[965]={"张根灿","",240,60,60,60,61,60,0,0};type[965]=14;
guo[966]={"张豪","",240,60,60,60,61,60,0,0};type[966]=2;
guo[967]={"张昊城","",160,40,40,40,46,40,0,0};type[967]=-15;
guo[968]={"张浩渺","",160,40,40,40,46,40,0,0};type[968]=-3;
guo[969]={"张加乔","",160,40,40,40,46,40,0,0};type[969]=-6;
guo[970]={"张嘉琦","",160,40,40,40,46,40,0,0};type[970]=-14;
guo[971]={"张坚秋","",240,60,60,60,61,60,0,0};type[971]=6;
guo[972]={"张江","",240,60,60,60,61,60,0,0};type[972]=3;
guo[973]={"张杰","",160,40,40,40,46,40,0,0};type[973]=-9;
guo[974]={"张洁慧","",240,60,60,60,61,60,0,0};type[974]=16;
guo[975]={"张居正","",160,40,40,40,46,40,0,0};type[975]=-9;
guo[976]={"张凯程","",160,40,40,40,46,40,0,0};type[976]=-11;
guo[977]={"张乐行","",160,40,40,40,46,40,0,0};type[977]=-10;
guo[978]={"张蕾","",286,72,72,72,76,70,0,0};type[978]=12;
guo[979]={"张琳洁","",160,40,40,40,46,40,0,0};type[979]=-3;
guo[980]={"张泠璞","",160,40,40,40,46,40,0,0};type[980]=-5;
guo[981]={"张刘灯","",160,40,40,40,46,40,0,0};type[981]=-15;
guo[982]={"张璐吉","",240,60,60,60,61,60,0,0};type[982]=3;
guo[983]={"张美玲","",160,40,40,40,46,40,0,0};type[983]=-4;
guo[984]={"张米琪","",160,40,40,40,46,40,0,0};type[984]=-1;
guo[985]={"张楠","",160,40,40,40,46,40,0,0};type[985]=-13;
guo[986]={"张世聪","",160,40,40,40,46,40,0,0};type[986]=-11;
guo[987]={"张伟丰","",240,60,60,60,61,60,0,0};type[987]=2;
guo[988]={"张文杰","",160,40,40,40,46,40,0,0};type[988]=-15;
guo[989]={"张小娟","",240,60,60,60,61,60,0,0};type[989]=13;
guo[990]={"张晓冉","",160,40,40,40,46,40,0,0};type[990]=-14;
guo[991]={"张欣泽","",160,40,40,40,46,40,0,0};type[991]=-12;
guo[992]={"张杨含笑","",160,40,40,40,46,40,0,0};type[992]=-9;
guo[993]={"张尧","",340,85,85,85,91,85,0,0};type[993]=19;
guo[994]={"张叶","",240,60,60,60,61,60,0,0};type[994]=13;
guo[995]={"张一弛","",160,40,40,40,46,40,0,0};type[995]=-4;
guo[996]={"张怡婷","",160,40,40,40,46,40,0,0};type[996]=-10;
guo[997]={"张旖雯","",160,40,40,40,46,40,0,0};type[997]=-4;
guo[998]={"张译丹","",160,40,40,40,46,40,0,0};type[998]=-13;
guo[999]={"张羿","",160,40,40,40,46,40,0,0};type[999]=0;
guo[1000]={"张逸凡","",160,40,40,40,46,40,0,0};type[1000]=-10;
guo[1001]={"张逸静","",160,40,40,40,46,40,0,0};type[1001]=-6;
guo[1002]={"张逸群","",160,40,40,40,46,40,0,0};type[1002]=-10;
guo[1003]={"张逸涛","",160,40,40,40,46,40,0,0};type[1003]=-6;
guo[1004]={"张滢","",160,40,40,40,46,40,0,0};type[1004]=-12;
guo[1005]={"张于晨","",160,40,40,40,46,40,0,0};type[1005]=-16;
guo[1006]={"张与时","",160,40,40,40,46,40,0,0};type[1006]=-8;
guo[1007]={"张宇柠","",160,40,40,40,46,40,0,0};type[1007]=-16;
guo[1008]={"张羽廷","",160,40,40,40,46,40,0,0};type[1008]=-15;
guo[1009]={"张雨萌","",160,40,40,40,46,40,0,0};type[1009]=-8;
guo[1010]={"张雨倩","",160,40,40,40,46,40,0,0};type[1010]=-1;
guo[1011]={"张雨婷","",160,40,40,40,46,40,0,0};type[1011]=-3;
guo[1012]={"张玥","",160,40,40,40,46,40,0,0};type[1012]=-6;
guo[1013]={"张越爱","",210,50,50,60,46,50,0,0};type[1013]=1;
guo[1014]={"张泽煜","",160,40,40,40,46,40,0,0};type[1014]=-2;
guo[1015]={"张政","",160,40,40,40,46,40,0,0};type[1015]=-2;
guo[1016]={"张洲","",160,40,40,40,46,40,0,0};type[1016]=-15;
guo[1017]={"张竹青","",160,40,40,40,46,40,0,0};type[1017]=-4;
guo[1018]={"张卓燚","",240,60,60,60,61,60,0,0};type[1018]=18;
guo[1019]={"张祖农","",240,60,60,60,61,60,0,0};type[1019]=9;
guo[1020]={"章嘉祺","",160,40,40,40,46,40,0,0};type[1020]=-7;
guo[1021]={"章俊杰","",160,40,40,40,46,40,0,0};type[1021]=-4;
guo[1022]={"章凯雯","",160,40,40,40,46,40,0,0};type[1022]=-6;
guo[1023]={"章梁","",160,40,40,40,46,40,0,0};type[1023]=-12;
guo[1024]={"章彤彤","",160,40,40,40,46,40,0,0};type[1024]=-11;
guo[1025]={"章一鸣","",160,40,40,40,46,40,0,0};type[1025]=-16;
guo[1026]={"章一庄","",160,40,40,40,46,40,0,0};type[1026]=-6;
guo[1027]={"章雨静","",160,40,40,40,46,40,0,0};type[1027]=-15;
guo[1028]={"赵晨含","",160,40,40,40,46,40,0,0};type[1028]=-9;
guo[1029]={"赵晨涛","",160,40,40,40,46,40,0,0};type[1029]=-2;
guo[1030]={"赵华琴","",160,40,40,40,46,40,0,0};type[1030]=-14;
guo[1031]={"赵佳龙","",160,40,40,40,46,40,0,0};type[1031]=-1;
guo[1032]={"赵乐毅","",160,40,40,40,46,40,0,0};type[1032]=-10;
guo[1033]={"赵楠","",160,40,40,40,46,40,0,0};type[1033]=-12;
guo[1034]={"赵翔宇","",160,40,40,40,46,40,0,0};type[1034]=-8;
guo[1035]={"赵潇阳","",160,40,40,40,46,40,0,0};type[1035]=-11;
guo[1036]={"赵炫承","",160,40,40,40,46,40,0,0};type[1036]=-14;
guo[1037]={"赵逸凡","",160,40,40,40,46,40,0,0};type[1037]=-4;
guo[1038]={"赵煜文","",160,40,40,40,46,40,0,0};type[1038]=-12;
guo[1039]={"赵元德","",160,40,40,40,46,40,0,0};type[1039]=-15;
guo[1040]={"赵正瑜","",240,60,60,60,61,60,0,0};type[1040]=8;
guo[1041]={"郑栋杰","",160,40,40,40,46,40,0,0};type[1041]=-13;
guo[1042]={"郑楠","",160,40,40,40,46,40,0,0};type[1042]=-8;
guo[1043]={"郑晴晴","",240,60,60,60,61,60,0,0};type[1043]=8;
guo[1044]={"郑小平","",240,60,60,60,61,60,0,0};type[1044]=16;
guo[1045]={"郑艺航","",160,40,40,40,46,40,0,0};type[1045]=-11;
guo[1046]={"郑子焓","",160,40,40,40,46,40,0,0};type[1046]=-16;
guo[1047]={"钟慧军","",240,60,60,60,61,60,0,0};type[1047]=16;
guo[1048]={"钟佳琦","",160,40,40,40,46,40,0,0};type[1048]=-14;
guo[1049]={"钟璟","",160,40,40,40,46,40,0,0};type[1049]=-9;
guo[1050]={"钟利华","",240,60,60,60,61,60,0,0};type[1050]=12;
guo[1051]={"钟林昊","",160,40,40,40,46,40,0,0};type[1051]=-3;
guo[1052]={"钟敏宜","",160,40,40,40,46,40,0,0};type[1052]=-14;
guo[1053]={"钟茜","",160,40,40,40,46,40,0,0};type[1053]=-16;
guo[1054]={"钟诗颖","",160,40,40,40,46,40,0,0};type[1054]=-2;
guo[1055]={"钟一韬","",160,40,40,40,46,40,0,0};type[1055]=-16;
guo[1056]={"钟奕楠","",160,40,40,40,46,40,0,0};type[1056]=-16;
guo[1057]={"周冰洁","",160,40,40,40,46,40,0,0};type[1057]=-14;
guo[1058]={"周陈滢","",160,40,40,40,46,40,0,0};type[1058]=-9;
guo[1059]={"周程扬","",160,40,40,40,46,40,0,0};type[1059]=-10;
guo[1060]={"周傅毅楠","",160,40,40,40,46,40,0,0};type[1060]=-9;
guo[1061]={"周国才","",240,60,60,60,61,60,0,0};type[1061]=10;
guo[1062]={"周寒悦","",160,40,40,40,46,40,0,0};type[1062]=-13;
guo[1063]={"周锦辉","",160,40,40,40,46,40,0,0};type[1063]=-12;
guo[1064]={"周伶滢","",160,40,40,40,46,40,0,0};type[1064]=-14;
guo[1065]={"周文龙","",269,68,68,68,61,65,0,0};type[1065]=3;
guo[1066]={"周文阳","",240,60,60,60,61,60,0,0};type[1066]=13;
guo[1067]={"周笑天","",160,40,40,40,46,40,0,0};type[1067]=-11;
guo[1068]={"周一丹","",160,40,40,40,46,40,0,0};type[1068]=-7;
guo[1069]={"周颖","",160,40,40,40,46,40,0,0};type[1069]=-14;
guo[1070]={"周宇辰","",160,40,40,40,46,40,0,0};type[1070]=-15;
guo[1071]={"周宇婷","",160,40,40,40,46,40,0,0};type[1071]=-6;
guo[1072]={"周雨帆","",160,40,40,40,46,40,0,0};type[1072]=-7;
guo[1073]={"周泽浩","",160,40,40,40,46,40,0,0};type[1073]=-3;
guo[1074]={"周展逸","",160,40,40,40,46,40,0,0};type[1074]=-15;
guo[1075]={"周正昊","",160,40,40,40,46,40,0,0};type[1075]=-5;
guo[1076]={"周正源","",160,40,40,40,46,40,0,0};type[1076]=-11;
guo[1077]={"周郅杰","",160,40,40,40,46,40,0,0};type[1077]=-15;
guo[1078]={"周卓效","",160,40,40,40,46,40,0,0};type[1078]=-5;
guo[1079]={"朱谷兰","",240,60,60,60,61,60,0,0};type[1079]=16;
guo[1080]={"朱佳敏","",160,40,40,40,46,40,0,0};type[1080]=-7;
guo[1081]={"朱瑾","",160,40,40,40,46,40,0,0};type[1081]=-14;
guo[1082]={"朱力宇","",160,40,40,40,46,40,0,0};type[1082]=-13;
guo[1083]={"朱玛莉","",240,60,60,60,61,60,0,0};type[1083]=4;
guo[1084]={"朱时妙","",240,60,60,60,61,60,0,0};type[1084]=13;
guo[1085]={"朱水军","",346,87,87,87,91,85,0,0};type[1085]=19;
guo[1086]={"朱雯","",400,100,100,100,106,100,0,0};type[1086]=20;
guo[1087]={"朱晓颖","",160,40,40,40,46,40,0,0};type[1087]=-6;
guo[1088]={"朱欣怡","",160,40,40,40,46,40,0,0};type[1088]=-13;
guo[1089]={"朱幸晨","",160,40,40,40,46,40,0,0};type[1089]=-7;
guo[1090]={"朱媛","",240,60,60,60,61,60,0,0};type[1090]=4;
guo[1091]={"朱仲达","",160,40,40,40,46,40,0,0};type[1091]=-3;
guo[1092]={"朱洲明","",160,40,40,40,46,40,0,0};type[1092]=-9;
guo[1093]={"诸迪洋","",160,40,40,40,46,40,0,0};type[1093]=-6;
guo[1094]={"诸佳英","",240,60,60,60,61,60,0,0};type[1094]=18;
guo[1095]={"诸梦琴","",160,40,40,40,46,40,0,0};type[1095]=-14;
guo[1096]={"诸思湉","",160,40,40,40,46,40,0,0};type[1096]=-8;
guo[1097]={"诸咏涛","",160,40,40,40,46,40,0,0};type[1097]=-2;
guo[1098]={"竹韵","",160,40,40,40,46,40,0,0};type[1098]=-9;
guo[1099]={"祝涵瑜","",160,40,40,40,46,40,0,0};type[1099]=-14;
guo[1100]={"祝嘉君","",160,40,40,40,46,40,0,0};type[1100]=-7;
guo[1101]={"祝建强","",240,60,60,60,61,60,0,0};type[1101]=14;
guo[1102]={"祝晓斌","",160,40,40,40,46,40,0,0};type[1102]=-15;
guo[1103]={"祝欣妍","",160,40,40,40,46,40,0,0};type[1103]=-4;
guo[1104]={"祝元仪","",160,40,40,40,46,40,0,0};type[1104]=-9;
guo[1105]={"祝元泽","",160,40,40,40,46,40,0,0};type[1105]=-5;
guo[1106]={"祝智浩","",240,60,60,60,61,60,0,0};type[1106]=13;
guo[1107]={"邹婕","",160,40,40,40,46,40,0,0};type[1107]=-14;
guo[1108]={"邹雁杭","",160,40,40,40,46,40,0,0};type[1108]=-7;
for(int i=1;i<=cnt;i++)for(int j=i+1;j<=cnt;j++){
	tu[i][j]=tu[j][i]=rand()%90+210;
	if(type[i]==type[j])tu[i][j]=tu[j][i]=min(tu[i][j],rand()%90+10);
	if(type[i]>18&&type[j]<19)tu[i][j]+=200,tu[j][i]+=200;
	if(type[j]>18&&type[i]<19)tu[i][j]+=200,tu[j][i]+=200;
}tu[884][149]=1;
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			sh[i]=0;du[i]=0;xz[i]=0;q[i]=0;bj[i]=i;xT[i]=0;gg[i]=0;si[i]=0;
			guo[i].tu=guo[i].name.substr(guo[i].name.length()-2,2);
			guo[i].tu+="土";if(guo[i].tu=="土土")guo[i].tu="祥土";
			if(i==8)guo[i].tu="土地";
		}guo[39].name+="(T)",guo[40].name+="(S)";Y=2017;M=9;W=0;YY=0;MM=0;WW=1;
}
	if(T==22){cnt=51;orz="同学";typ=0;ty=1;d1=20;d2=40;_=0;rev=0;
guo[1].name="陈义兵（全能神）";
guo[2].name="陈雨珂";
guo[3].name="陈锦涛";
guo[4].name="陈立  ";
guo[5].name="陈诺  ";
guo[6].name="陈幸媛";
guo[7].name="陈奕然";
guo[8].name="陈益扬";
guo[9].name="杜逍云";
guo[10].name="方沁奕";
guo[11].name="冯宇飞";
guo[12].name="顾家俊";
guo[13].name="胡寒昱";
guo[14].name="贾谷兰";
guo[15].name="蒋王英";
guo[16].name="金妍池";
guo[17].name="金玉婷";
guo[18].name="晋诗羽";
guo[19].name="凌栋钦";
guo[20].name="柳嘉仪";
guo[21].name="鲁雨成";
guo[22].name="鲁毅涛";
guo[23].name="庞琳杰";
guo[24].name="任和  ";
guo[25].name="吕晓筱";
guo[26].name="邵无为";
guo[27].name="沈晨阳";
guo[28].name="沈浚哲";
guo[29].name="寿霆丰";
guo[30].name="孙丹娜";
guo[31].name="孙麒婷";
guo[32].name="汪垚程";
guo[33].name="王怡能";
guo[34].name="王宇杰";
guo[35].name="相佳玥";
guo[36].name="相卓伟";
guo[37].name="许佳烨";
guo[38].name="严聚卫";
guo[39].name="叶灵  ";
guo[40].name="余晨阳";
guo[41].name="俞晨亮";
guo[42].name="俞林  ";
guo[43].name="俞杨  ";
guo[44].name="张楠  ";
guo[45].name="郑栋杰";
guo[46].name="周寒悦";
guo[47].name="张译丹";
guo[48].name="朱力宇";
guo[49].name="朱欣怡";
guo[50].name="傅芳芳";
guo[51].name="BOSS韩小红";
for(int i=1;i<=cnt;i++)for(int j=i+1;j<=cnt;j++){
	tu[i][j]=tu[j][i]=rand()%90+10;
}
for(i=1;i<cnt;i++)guo[i]={guo[i].name,"",200,50,50,50,61,50,0,0};
guo[51]={guo[51].name,"",2000,100,100,100,250,100,0,0};
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			sh[i]=0;du[i]=0;xz[i]=0;q[i]=0;bj[i]=i;xT[i]=0;gg[i]=0;si[i]=0;
			guo[i].tu=guo[i].name[4]==' '?guo[i].name.substr(2,2):guo[i].name.substr(4,2);
			guo[i].tu+="土";
			if(i==51)guo[i].tu="妖土";
			if(i==1)guo[i].tu="神土";
			if(i==48)guo[i].tu="猪土";
			if(i==32)guo[i].tu="狗土";
		}Y=2017;M=9;W=-1;YY=0;MM=0;WW=3;
	}
	if(T==7){cnt=3;orz="同学";typ=1;ty=1;d1=20;d2=1e9;_=0;rev=0;
guo[1].name="劳伊栋";guo[1].guoli=0;guo[1].tudi=50;guo[1].jingji=400;guo[1].junli=50;guo[1].bingli=42;guo[1].zhengzhi=0;
guo[2].name="李之琦";guo[2].guoli=0;guo[2].tudi=50;guo[2].jingji=400;guo[2].junli=50;guo[2].bingli=20;guo[2].zhengzhi=0;
guo[3].name="洪珂凡";guo[3].guoli=0;guo[3].tudi=50;guo[3].jingji=400;guo[3].junli=50;guo[3].bingli=10;guo[3].zhengzhi=0;
guo[1].zhen=2;guo[2].zhen=guo[3].zhen=1;guo[2].tizhi=guo[3].tizhi=1;
		tu[1][2]=tu[2][1]=10;tu[1][3]=tu[3][1]=tu[2][3]=tu[3][2]=1000;
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			xT[i]=guo[i].tizhi;
			xz[i]=guo[i].zhen;
			sh[i]=0;du[i]=0;bj[i]=i;gg[i]=0;si[i]=0;q[i]=1;
			guo[i].tu="  土";
		}Y=2015;M=12;W=7;YY=MM=0;WW=1;
	}
	if(T==9){cnt=2;orz="同学";typ=0;ty=1;d1=0;d2=1e9;_=0;rev=0;
guo[1].name="bdf";guo[1].guoli=0;guo[1].tudi=600;guo[1].jingji=1100;guo[1].junli=10000;guo[1].bingli=0;guo[1].zhengzhi=0;
guo[2].name="NiroBC";guo[2].guoli=-20000;guo[2].tudi=200;guo[2].jingji=11000;guo[2].junli=2000;guo[2].bingli=8000;guo[2].zhengzhi=0;
guo[2].tizhi=guo[1].tizhi=6;
		tu[1][2]=tu[2][1]=5000;
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			xT[i]=guo[i].tizhi;
			xz[i]=guo[i].zhen;
			sh[i]=0;du[i]=0;bj[i]=i;gg[i]=3;si[i]=0;q[i]=2;
			guo[i].tu="  土";
		}Y=2017;M=7;W=20;YY=MM=0;WW=3;
	}
	if(T==1){cnt=12;orz="国家";typ=0;ty=1;d1=25;d2=40;_=0;rev=0;
guo[1].name="秦";guo[1].guoli=0;guo[1].tudi=50;guo[1].jingji=40;guo[1].junli=45;guo[1].bingli=30;guo[1].zhengzhi=55;
guo[2].name="蜀";guo[2].guoli=0;guo[2].tudi=35;guo[2].jingji=30;guo[2].junli=30;guo[2].bingli=20;guo[2].zhengzhi=35;
guo[3].name="晋";guo[3].guoli=0;guo[3].tudi=60;guo[3].jingji=50;guo[3].junli=40;guo[3].bingli=40; guo[3].zhengzhi=45;
guo[4].name="郑";guo[4].guoli=0;guo[4].tudi=30;guo[4].jingji=50;guo[4].junli=37;guo[4].bingli=30; guo[4].zhengzhi=45;
guo[5].name="卫";guo[5].guoli=0;guo[5].tudi=20;guo[5].jingji=35;guo[5].junli=35;guo[5].bingli=20; guo[5].zhengzhi=45;
guo[6].name="宋";guo[6].guoli=0;guo[6].tudi=35;guo[6].jingji=40;guo[6].junli=37;guo[6].bingli=25;guo[6].zhengzhi=45;
guo[7].name="楚";guo[7].guoli=0;guo[7].tudi=90;guo[7].jingji=35;guo[7].junli=42;guo[7].bingli=55; guo[7].zhengzhi=35; 
guo[8].name="齐";guo[8].guoli=0;guo[8].tudi=50;guo[8].jingji=70;guo[8].junli=43;guo[8].bingli=35; guo[8].zhengzhi=45;
guo[9].name="鲁";guo[9].guoli=0;guo[9].tudi=30;guo[9].jingji=30;guo[9].junli=42;guo[9].bingli=35; guo[9].zhengzhi=60;
guo[10].name="吴";guo[10].guoli=0;guo[10].tudi=25;guo[10].jingji=30;guo[10].junli=38;guo[10].bingli=40; guo[10].zhengzhi=40;
guo[11].name="越";guo[11].guoli=0;guo[11].tudi=25;guo[11].jingji=30;guo[11].junli=40;guo[11].bingli=40;guo[11].zhengzhi=40;
guo[12].name="北燕";guo[12].guoli=0;guo[12].tudi=45;guo[12].jingji=30;guo[12].junli=38;guo[12].bingli=60; guo[12].zhengzhi=40; 
		tu[1][2]=tu[2][1]=50;
		tu[1][3]=tu[3][1]=10;
		tu[1][4]=tu[4][1]=30;
		tu[1][5]=tu[5][1]=35;
		tu[1][6]=tu[6][1]=50;
		tu[1][7]=tu[7][1]=35;
		tu[1][8]=tu[8][1]=60;
		tu[1][9]=tu[9][1]=55;
		tu[1][10]=tu[10][1]=65;
		tu[1][11]=tu[11][1]=75;
		tu[1][12]=tu[12][1]=50;
		tu[2][3]=tu[3][2]=60;
		tu[2][4]=tu[4][2]=90;
		tu[2][5]=tu[5][2]=95;
		tu[2][6]=tu[6][2]=100;
		tu[2][7]=tu[7][2]=105;
		tu[2][8]=tu[8][2]=120;
		tu[2][9]=tu[9][2]=115;
		tu[2][10]=tu[10][2]=125;
		tu[2][11]=tu[11][2]=105;
		tu[2][12]=tu[12][2]=110;
		tu[3][4]=tu[4][3]=10;
		tu[3][5]=tu[5][3]=10;
		tu[3][6]=tu[6][3]=30;
		tu[3][7]=tu[7][3]=40;
		tu[3][8]=tu[8][3]=50;
		tu[3][9]=tu[9][3]=50;
		tu[3][10]=tu[10][3]=55;
		tu[3][11]=tu[11][3]=65;
		tu[3][12]=tu[12][3]=40;
		tu[4][5]=tu[5][4]=5;
		tu[4][6]=tu[6][4]=20;
		tu[4][7]=tu[7][4]=30;
		tu[4][8]=tu[8][4]=40;
		tu[4][9]=tu[9][4]=40;
		tu[4][10]=tu[10][4]=50;
		tu[4][11]=tu[11][4]=55;
		tu[4][12]=tu[12][4]=40;
		tu[5][6]=tu[6][5]=10;
		tu[5][7]=tu[7][5]=20;
		tu[5][8]=tu[8][5]=30;
		tu[5][9]=tu[9][5]=30;
		tu[5][10]=tu[10][5]=40;
		tu[5][11]=tu[11][5]=45;
		tu[5][12]=tu[12][5]=30;
		tu[6][7]=tu[7][6]=10;
		tu[6][8]=tu[8][6]=20;
		tu[6][9]=tu[9][6]=20;
		tu[6][10]=tu[10][6]=30;
		tu[6][11]=tu[11][6]=35;
		tu[6][12]=tu[12][6]=30;
		tu[7][8]=tu[8][7]=30;
		tu[7][9]=tu[9][7]=30;
		tu[7][10]=tu[10][7]=20;
		tu[7][11]=tu[11][7]=25;
		tu[7][12]=tu[12][7]=30;
		tu[8][9]=tu[9][8]=10;
		tu[8][10]=tu[10][8]=20;
		tu[8][11]=tu[11][8]=25;
		tu[8][12]=tu[12][8]=20;
		tu[9][10]=tu[10][9]=20;
		tu[9][11]=tu[11][9]=25;
		tu[9][12]=tu[12][9]=35;
		tu[10][11]=tu[11][10]=25;
		tu[10][12]=tu[12][10]=55;
		tu[11][12]=tu[12][11]=60;
		for(i=1;i<=cnt;i++){
			xg[i]=guo[i].guoli;
			xb[i]=guo[i].bingli;
			xj[i]=guo[i].junli;
			xJ[i]=guo[i].jingji;
			xt[i]=guo[i].tudi;
			xZ[i]=guo[i].zhengzhi;
			sh[i]=0;du[i]=0;xz[i]=0;q[i]=0;bj[i]=i;xT[i]=0;gg[i]=0;si[i]=0;
			guo[i].tu="国土";
		}Y=-500;M=1;W=1;YY=10;MM=WW=0;
	}
	if(T==2){cnt=20;orz="国家";typ=0;ty=1;d1=100,d2=100;_=0;rev=0;
	guo[1].name="挪威";guo[1].guoli=1000;guo[1].tudi=50;guo[1].jingji=360;guo[1].bingli=50;guo[1].junli=60;guo[1].zhengzhi=500;guo[1].tizhi=1;
	guo[2].name="瑞典";guo[2].guoli=900;guo[2].tudi=30;guo[2].jingji=360;guo[2].bingli=50;guo[2].junli=54;guo[2].zhengzhi=530;guo[2].tizhi=1;
	guo[3].name="丹麦";guo[3].guoli=700;guo[3].tudi=20;guo[3].jingji=400;guo[3].bingli=30;guo[3].junli=50;guo[3].zhengzhi=570;guo[3].tizhi=1;
	guo[4].name="基辅";guo[4].guoli=400;guo[4].tudi=100;guo[4].jingji=200;guo[4].bingli=130;guo[4].junli=55;guo[4].zhengzhi=400;guo[4].tizhi=1;
	guo[5].name="波兰";guo[5].guoli=500;guo[5].tudi=35;guo[5].jingji=300;guo[5].bingli=90;guo[5].junli=58;guo[5].zhengzhi=500;guo[5].tizhi=1;
	guo[6].name="日耳曼";guo[6].guoli=1500;guo[6].tudi=60;guo[6].jingji=430;guo[6].bingli=200;guo[6].junli=75;guo[6].zhengzhi=550;guo[6].tizhi=1;
	guo[7].name="法兰西";guo[7].guoli=1500;guo[7].tudi=55;guo[7].jingji=400;guo[7].bingli=160;guo[7].junli=62;guo[7].zhengzhi=580;guo[7].tizhi=1;
	guo[8].name="捷克";guo[8].guoli=400;guo[8].tudi=20;guo[8].jingji=300;guo[8].bingli=65;guo[8].junli=55;guo[8].zhengzhi=490;guo[8].tizhi=1;
	guo[9].name="匈牙利";guo[9].guoli=800;guo[9].tudi=35;guo[9].jingji=290;guo[9].bingli=100;guo[9].junli=58;guo[9].zhengzhi=460;guo[9].tizhi=1;
	guo[10].name="勃艮第";guo[10].guoli=300;guo[10].tudi=30;guo[10].jingji=320;guo[10].bingli=60;guo[10].junli=50;guo[10].zhengzhi=500;guo[10].tizhi=1;
	guo[11].name="伦巴第";guo[11].guoli=400;guo[11].tudi=30;guo[11].jingji=480;guo[11].bingli=40;guo[11].junli=45;guo[11].zhengzhi=600;guo[11].tizhi=1;
	guo[12].name="教皇国";guo[12].guoli=600;guo[12].tudi=10;guo[12].jingji=800;guo[12].bingli=20;guo[12].junli=40;guo[12].zhengzhi=500;guo[12].tizhi=1;
	guo[13].name="西保加利亚";guo[13].guoli=600;guo[13].tudi=30;guo[13].jingji=400;guo[13].bingli=70;guo[13].junli=50;guo[13].zhengzhi=490;guo[13].tizhi=1;
	guo[14].name="拜占庭";guo[14].guoli=1700;guo[14].tudi=70;guo[14].jingji=200;guo[14].bingli=200;guo[14].junli=41;guo[14].zhengzhi=500;guo[14].tizhi=1;
	guo[15].name="科尔多瓦哈里发";guo[15].guoli=600;guo[15].tudi=50;guo[15].jingji=140;guo[15].bingli=50;guo[15].junli=49;guo[15].zhengzhi=400;guo[15].tizhi=1;
	guo[16].name="雷翁";guo[16].guoli=600;guo[16].tudi=20;guo[16].jingji=120;guo[16].bingli=30;guo[16].junli=43;guo[16].zhengzhi=390;guo[16].tizhi=1;
	guo[17].name="威尼斯";guo[17].guoli=3000;guo[17].tudi=5;guo[17].jingji=2000;guo[17].bingli=30;guo[17].junli=40;guo[17].zhengzhi=700;guo[17].tizhi=1;
	guo[18].name="英格兰";guo[18].guoli=500;guo[18].tudi=30;guo[18].jingji=440;guo[18].bingli=60;guo[18].junli=50;guo[18].zhengzhi=540;guo[18].tizhi=1;
	guo[19].name="伦巴尔德";guo[19].guoli=300;guo[19].tudi=15;guo[19].jingji=500;guo[19].bingli=30;guo[19].junli=45;guo[19].zhengzhi=580;guo[19].tizhi=1;
	guo[20].name="苏格兰";guo[20].guoli=400;guo[20].tudi=25;guo[20].jingji=300;guo[20].bingli=40;guo[20].junli=53;guo[20].zhengzhi=450;guo[20].tizhi=1;
	for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++)tu[i][j]=999999;
	tu[1][18]=tu[18][1]=200;tu[1][2]=40;
	tu[2][3]=tu[3][2]=60;tu[2][4]=tu[4][2]=180;tu[2][18]=tu[18][2]=220;
	tu[3][6]=tu[6][3]=30;tu[18][3]=tu[3][18]=150;
	tu[4][5]=tu[5][4]=30;tu[4][9]=tu[9][4]=30;tu[4][14]=tu[14][4]=200;
	tu[5][6]=tu[9][5]=30;tu[5][8]=tu[8][5]=30;tu[5][9]=tu[9][5]=30;
	tu[6][8]=tu[8][6]=30;tu[6][9]=tu[9][6]=30;tu[6][11]=tu[11][6]=30;tu[6][10]=tu[10][6]=30;tu[6][7]=tu[7][6]=30;tu[6][18]=60;
	tu[7][10]=tu[10][7]=30;tu[7][15]=tu[15][7]=30;tu[7][18]=60;
	tu[8][9]=tu[9][8]=30;
	tu[9][13]=tu[13][9]=10;
	tu[10][11]=tu[11][10]=30;
	tu[11][12]=tu[12][11]=30;
	tu[12][19]=tu[19][12]=30;
	tu[13][19]=tu[19][13]=50; tu[14][13]=tu[13][14]=40;
	tu[15][7]=tu[7][15]=60;
	tu[15][16]=tu[16][15]=40;
	tu[17][11]=tu[11][17]=0;
	tu[18][20]=tu[20][18]=70;
	for(int i=1;i<=cnt;i++)
	for(int j=1;j<=cnt;j++)
	for(int k=1;k<=cnt;k++){
		if(i==j||j==k||i==k)continue;
		tu[j][k]=min(tu[j][i]+tu[i][k],tu[j][k]);
	}
	for(i=1;i<=cnt;i++){
		xg[i]=guo[i].guoli;
		xb[i]=guo[i].bingli;
		xj[i]=guo[i].junli;
		xJ[i]=guo[i].jingji;
		xt[i]=guo[i].tudi;
		xZ[i]=guo[i].zhengzhi;
		sh[i]=0;du[i]=0;xz[i]=0;q[i]=1;bj[i]=i;xT[i]=1;gg[i]=0;si[i]=0;
		guo[i].tu="国土";
	}Y=1000;M=1;W=1;YY=1;MM=WW=0;
	}
	if(T==3){cnt=28;orz="国家";typ=1;ty=1;d1=300,d2=1e9;_=500;rev=0;
for(i=1;i<=cnt;i++)q[i]=1,gg[i]=2;z1="同盟国";z2="轴心国"; 
guo[1].zhen=1;	guo[1].name="挪威";guo[1].guoli=5000;guo[1].tudi=40;guo[1].jingji=600;guo[1].bingli=150;guo[1].junli=150;guo[1].zhengzhi=2500;guo[1].tizhi=4;
guo[2].zhen=1;	guo[2].name="瑞典";guo[2].guoli=4000;guo[2].tudi=45;guo[2].jingji=550;guo[2].bingli=100;guo[2].junli=50;guo[2].zhengzhi=2300;guo[2].tizhi=4;
guo[3].zhen=0;	guo[3].name="芬兰";guo[3].guoli=6000;guo[3].tudi=35;guo[3].jingji=550;guo[3].bingli=200;guo[3].junli=200;guo[3].zhengzhi=2100;guo[3].tizhi=4;
  guo[4].zhen=1;	guo[4].name="英国";guo[4].guoli=10000;guo[4].tudi=40;guo[4].jingji=1800;guo[4].bingli=500;guo[4].junli=400;guo[4].zhengzhi=3000;guo[4].tizhi=4;
  guo[5].zhen=0;	guo[5].name="苏联";guo[5].guoli=0;guo[5].tudi=350;guo[5].jingji=280;guo[5].bingli=1000;guo[5].junli=120;guo[5].zhengzhi=2005;guo[5].tizhi=5;
guo[6].zhen=1;	guo[6].name="加拿大";guo[6].guoli=500;guo[6].tudi=230;guo[6].jingji=150;guo[6].bingli=50;guo[6].junli=30;guo[6].zhengzhi=2010;guo[6].tizhi=4;
guo[7].zhen=0;	guo[7].name="荷兰";guo[7].guoli=1000;guo[7].tudi=10;guo[7].jingji=850;guo[7].bingli=50;guo[7].junli=30;guo[7].zhengzhi=2355;guo[7].tizhi=4;
guo[8].zhen=2;	guo[8].name="德国";guo[8].guoli=5000;guo[8].tudi=55;guo[8].jingji=1500;guo[8].bingli=700;guo[8].junli=1100;guo[8].zhengzhi=6005;guo[8].tizhi=6;
guo[9].zhen=1;	guo[9].name="波兰";guo[9].guoli=3000;guo[9].tudi=40;guo[9].jingji=500;guo[9].bingli=400;guo[9].junli=200;guo[9].zhengzhi=1900;guo[9].tizhi=2;
guo[10].zhen=1;	guo[10].name="法国";guo[10].guoli=8000;guo[10].tudi=55;guo[10].jingji=1000;guo[10].bingli=800;guo[10].junli=250;guo[10].zhengzhi=2800;guo[10].tizhi=4;
guo[11].zhen=0;	guo[11].name="匈牙利";guo[11].guoli=2000;guo[11].tudi=15;guo[11].jingji=450;guo[11].bingli=100;guo[11].junli=150;guo[11].zhengzhi=1800;guo[11].tizhi=3;
guo[12].zhen=0;	guo[12].name="西班牙";guo[12].guoli=500;guo[12].tudi=50;guo[12].jingji=420;guo[12].bingli=150;guo[12].junli=120;guo[12].zhengzhi=1300;guo[12].tizhi=3;
guo[13].zhen=2;	guo[13].name="意大利";guo[13].guoli=3000;guo[13].tudi=40;guo[13].jingji=600;guo[13].bingli=600;guo[13].junli=150;guo[13].zhengzhi=6005;guo[13].tizhi=6;
 guo[14].zhen=1;	guo[14].name="南斯拉夫";guo[14].guoli=2000;guo[14].tudi=50;guo[14].jingji=500;guo[14].bingli=300;guo[14].junli=200;guo[14].zhengzhi=1300;guo[14].tizhi=3;
guo[15].zhen=0;	guo[15].name="罗马尼亚";guo[15].guoli=1500;guo[15].tudi=30;guo[15].jingji=420;guo[15].bingli=200;guo[15].junli=150;guo[15].zhengzhi=1500;guo[15].tizhi=3;
 guo[16].zhen=0;	guo[16].name="美国";guo[16].guoli=3000;guo[16].tudi=220;guo[16].jingji=450;guo[16].bingli=300;guo[16].junli=50;guo[16].zhengzhi=6005;guo[16].tizhi=7;
guo[17].zhen=0;	guo[17].name="葡萄牙";guo[17].guoli=1000;guo[17].tudi=15;guo[17].jingji=800;guo[17].bingli=50;guo[17].junli=50;guo[17].zhengzhi=2500;guo[17].tizhi=4;
guo[18].zhen=1;	guo[18].name="希腊";guo[18].guoli=5000;guo[18].tudi=20;guo[18].jingji=850;guo[18].bingli=50;guo[18].junli=50;guo[18].zhengzhi=3005;guo[18].tizhi=4;
guo[19].zhen=0;	guo[19].name="土耳其";guo[19].guoli=2000;guo[19].tudi=60;guo[19].jingji=700;guo[19].bingli=150;guo[19].junli=250;guo[19].zhengzhi=2005;guo[19].tizhi=4;
guo[20].zhen=0;	guo[20].name="伊朗";guo[20].guoli=500;guo[20].tudi=50;guo[20].jingji=300;guo[20].bingli=300;guo[20].junli=120;guo[20].zhengzhi=1500;guo[20].tizhi=3;
 guo[21].zhen=1;	guo[21].name="中华民国";guo[21].guoli=0;guo[21].tudi=215;guo[21].jingji=200;guo[21].bingli=3000;guo[21].junli=80;guo[21].zhengzhi=2005;guo[21].tizhi=4;
 guo[22].zhen=1;	guo[22].name="中国共产党";guo[22].guoli=0;guo[22].tudi=35;guo[22].jingji=120;guo[22].bingli=200;guo[22].junli=300;guo[22].zhengzhi=2900;guo[22].tizhi=5;
guo[23].zhen=1;	guo[23].name="朝鲜";guo[23].guoli=500;guo[23].tudi=15;guo[23].jingji=50;guo[23].bingli=50;guo[23].junli=60;guo[23].zhengzhi=500;guo[23].tizhi=1;
guo[24].zhen=2;	guo[24].name="日本";guo[24].guoli=3000;guo[24].tudi=40;guo[24].jingji=1500;guo[24].bingli=800;guo[24].junli=400;guo[24].zhengzhi=6000;guo[24].tizhi=6;
guo[25].zhen=1;	guo[25].name="埃及";guo[25].guoli=300;guo[25].tudi=60;guo[25].jingji=200;guo[25].bingli=50;guo[25].junli=60;guo[25].zhengzhi=500;guo[25].tizhi=1;
guo[26].zhen=1;	guo[26].name="印度";guo[26].guoli=300;guo[26].tudi=100;guo[26].jingji=200;guo[26].bingli=200;guo[26].junli=150;guo[26].zhengzhi=1000;guo[26].tizhi=2;
 guo[27].zhen=1;	guo[27].name="澳大利亚";guo[27].guoli=2000;guo[27].tudi=130;guo[27].jingji=400;guo[27].bingli=100;guo[27].junli=30;guo[27].zhengzhi=2000;guo[27].tizhi=4;
guo[28].zhen=1;	guo[28].name="丹麦";guo[28].guoli=1000;guo[28].tudi=10;guo[28].jingji=800;guo[28].bingli=50;guo[28].junli=50;guo[28].zhengzhi=2700;guo[28].tizhi=4;
q[24]=2;q[8]=2;q[13]=2;q[10]=2;q[4]=2;
for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++)tu[i][j]=9999999;
	tu[1][2]=tu[2][1]=1000;tu[1][4]=tu[4][1]=500000;
	tu[2][3]=tu[3][2]=1000;tu[2][28]=tu[28][2]=3000;
	tu[3][5]=tu[5][3]=1000;
	tu[4][10]=tu[10][4]=500000;tu[4][6]=tu[6][4]=500000;
	tu[5][9]=tu[9][5]=2000;tu[5][24]=tu[24][5]=2000;tu[5][21]=tu[21][5]=1500;tu[5][11]=tu[11][5]=1000;tu[5][15]=tu[15][5]=1000;tu[5][19]=tu[19][5]=1000;tu[5][20]=tu[20][5]=1000;tu[5][16]=tu[16][5]=160000;
	tu[6][16]=tu[16][6]=1000;  
	tu[7][8]=tu[8][7]=500;tu[7][10]=tu[10][7]=500;
	tu[8][9]=tu[9][8]=500;tu[8][10]=tu[10][8]=40000;tu[8][11]=tu[11][8]=1000;tu[8][13]=tu[13][8]=500;tu[8][4]=tu[4][8]=500000;
	tu[9][11]=tu[11][9]=1000;
	tu[10][12]=tu[12][10]=1500;tu[10][13]=tu[13][10]=3000;tu[12][17]=tu[17][12]=500; 
	tu[11][15]=tu[15][11]=1000;tu[11][14]=1000;
	tu[12][16]=tu[16][12]=120000;
	tu[13][14]=tu[14][13]=2000;tu[13][25]=tu[25][13]=6000;tu[13][18]=tu[18][13]=2000;tu[14][15]=tu[15][14]=1000;tu[14][18]=tu[18][14]=1000;tu[13][25]=tu[25][13]=50000;
	tu[15][18]=tu[18][15]=150000;tu[15][19]=tu[19][15]=4000;
	tu[16][24]=tu[24][16]=120000;tu[16][27]=tu[27][16]=120000;
	tu[18][19]=tu[19][18]=1500;
	tu[19][20]=tu[20][19]=2000;
	tu[20][26]=tu[26][20]=2000;tu[20][21]=tu[21][20]=3000;
	tu[21][22]=tu[22][21]=1000;tu[21][24]=tu[24][21]=1000;
	tu[21][23]=tu[23][21]=2000;tu[21][26]=tu[26][21]=2000;tu[27][26]=tu[26][27]=9000;tu[27][24]=tu[24][27]=6000;
	tu[23][24]=tu[24][23]=1000;
	tu[8][28]=tu[28][8]=999;
	for(int i=1;i<=cnt;i++)
	for(int j=1;j<=cnt;j++)
	for(int l=1;l<=cnt;l++)
	if(i==j||j==l||l==i);else tu[j][l]=min(tu[j][l],tu[j][i]+tu[i][l]);
	tu[8][21]=tu[21][8]=10000;
	tu[13][21]=tu[21][13]=10000;
	for(i=1;i<=cnt;i++){
		xg[i]=guo[i].guoli;
		xb[i]=guo[i].bingli;
		xj[i]=guo[i].junli;
		xJ[i]=guo[i].jingji;
		xt[i]=guo[i].tudi;
		xZ[i]=guo[i].zhengzhi;
		xT[i]=guo[i].tizhi;
		xz[i]=guo[i].zhen;
		sh[i]=0;du[i]=0;bj[i]=i;gg[i]=2;si[i]=0;
		guo[i].tu="国土";
	}Y=1939;M=1;W=1;MM=1;YY=WW=0;for(int i=1;i<=100;i++)sh[i]=0;
	}
if(T==4){cnt=19;orz="人民";typ=2;ty=0;d1=300,d2=1e9;_=0;rev=0;
for(i=1;i<=cnt;i++)q[i]=2,gg[i]=3;z1="反董烨华集团";z2="董烨华集团"; 
guo[1].zhen=1;	guo[1].name="鲍东方";guo[1].guoli=5000;guo[1].tudi=200;guo[1].jingji=1100;guo[1].bingli=800;guo[1].junli=200;guo[1].zhengzhi=0;guo[1].tizhi=3;
guo[2].zhen=0;	guo[2].name="陈龙翀";guo[2].guoli=1000;guo[2].tudi=50;guo[2].jingji=1100;guo[2].bingli=150;guo[2].junli=150;guo[2].zhengzhi=0;guo[2].tizhi=2;
guo[3].zhen=0;	guo[3].name="陈齐治";guo[3].guoli=1000;guo[3].tudi=50;guo[3].jingji=1100;guo[3].bingli=150;guo[3].junli=150;guo[3].zhengzhi=0;guo[3].tizhi=2;
guo[4].zhen=0;	guo[4].name="褚步霄";guo[4].guoli=1000;guo[4].tudi=50;guo[4].jingji=1100;guo[4].bingli=150;guo[4].junli=150;guo[4].zhengzhi=0;guo[4].tizhi=2;
guo[5].zhen=0;	guo[5].name="傅乐天";guo[5].guoli=1000;guo[5].tudi=50;guo[5].jingji=1100;guo[5].bingli=150;guo[5].junli=150;guo[5].zhengzhi=0;guo[5].tizhi=2;
guo[6].zhen=0;	guo[6].name="郭楠";  guo[6].guoli=1000;guo[6].tudi=50;guo[6].jingji=1100;guo[6].bingli=150;guo[6].junli=150;guo[6].zhengzhi=0;guo[6].tizhi=2;
guo[7].zhen=0;	guo[7].name="何晨泽";guo[7].guoli=1000;guo[7].tudi=50;guo[7].jingji=1100;guo[7].bingli=150;guo[7].junli=150;guo[7].zhengzhi=0;guo[7].tizhi=2;
guo[8].zhen=0;	guo[8].name="李家成";guo[8].guoli=1000;guo[8].tudi=50;guo[8].jingji=1100;guo[8].bingli=150;guo[8].junli=150;guo[8].zhengzhi=0;guo[8].tizhi=2;
guo[9].zhen=0;	guo[9].name="沈序戎";guo[9].guoli=1000;guo[9].tudi=50;guo[9].jingji=1100;guo[9].bingli=150;guo[9].junli=150;guo[9].zhengzhi=0;guo[9].tizhi=2;
guo[10].zhen=0;	guo[10].name="寿家跃";guo[10].guoli=1000;guo[10].tudi=50;guo[10].jingji=1100;guo[10].bingli=150;guo[10].junli=150;guo[10].zhengzhi=0;guo[10].tizhi=2;
guo[11].zhen=0;	guo[11].name="田振楠";guo[11].guoli=1000;guo[11].tudi=50;guo[11].jingji=1100;guo[11].bingli=150;guo[11].junli=150;guo[11].zhengzhi=0;guo[11].tizhi=2;
guo[12].zhen=0;	guo[12].name="王天乐";guo[12].guoli=1000;guo[12].tudi=50;guo[12].jingji=1100;guo[12].bingli=150;guo[12].junli=150;guo[12].zhengzhi=0;guo[12].tizhi=2;
guo[13].zhen=0;	guo[13].name="王子习";guo[13].guoli=1000;guo[13].tudi=50;guo[13].jingji=1100;guo[13].bingli=150;guo[13].junli=150;guo[13].zhengzhi=0;guo[13].tizhi=2;
guo[14].zhen=0;	guo[14].name="徐希彦";guo[14].guoli=1000;guo[14].tudi=50;guo[14].jingji=1100;guo[14].bingli=150;guo[14].junli=150;guo[14].zhengzhi=0;guo[14].tizhi=2;
guo[15].zhen=0;	guo[15].name="詹致豪";guo[15].guoli=2500;guo[15].tudi=70;guo[15].jingji=1100;guo[15].bingli=300;guo[15].junli=300;guo[15].zhengzhi=0;guo[15].tizhi=2;
guo[16].zhen=0;	guo[16].name="张乐行";guo[16].guoli=1500;guo[16].tudi=55;guo[16].jingji=1100;guo[16].bingli=200;guo[16].junli=200;guo[16].zhengzhi=0;guo[16].tizhi=2;
guo[17].zhen=0;	guo[17].name="张逸凡";guo[17].guoli=2000;guo[17].tudi=61;guo[17].jingji=1100;guo[17].bingli=250;guo[17].junli=250;guo[17].zhengzhi=0;guo[17].tizhi=2;
guo[18].zhen=0;	guo[18].name="赵乐毅";guo[18].guoli=1000;guo[18].tudi=50;guo[18].jingji=1100;guo[18].bingli=150;guo[18].junli=150;guo[18].zhengzhi=0;guo[18].tizhi=2;
guo[19].zhen=2;	guo[19].name="董烨华";guo[19].guoli=5000;guo[19].tudi=200;guo[19].jingji=1100;guo[19].bingli=700;guo[19].junli=200;guo[19].zhengzhi=0;guo[19].tizhi=6;
	for(int i=1;i<=19;i++)for(int j=1;j<=19;j++)if(i==j)tu[i][j]=0;
	else if(i==1||j==1)tu[i][j]=2000;else if(i==19||j==19)tu[i][j]=1500;
	else tu[i][j]=1000;tu[1][19]=tu[19][1]=10000; 
	for(i=1;i<=cnt;i++){
		xg[i]=guo[i].guoli;
		xb[i]=guo[i].bingli;
		xj[i]=guo[i].junli;
		xJ[i]=guo[i].jingji;
		xt[i]=guo[i].tudi;
		xZ[i]=guo[i].zhengzhi;
		xT[i]=guo[i].tizhi;
		xz[i]=guo[i].zhen;
		sh[i]=0;du[i]=0;bj[i]=i;gg[i]=3;si[i]=0;
		guo[i].tu="国土";
	}Y=2016;M=1;W=0;MM=0;YY=0;WW=7;for(int i=1;i<=100;i++)sh[i]=0;
	}
	if(T==20){cnt=10;orz="老师";typ=0;ty=1;d1=250,d2=10000;_=0;rev=0;
	for(i=1;i<=cnt;i++)q[i]=1,gg[i]=1;
	guo[1].name="Melissa";guo[1].guoli=1000;guo[1].tudi=91;guo[1].jingji=600;guo[1].bingli=250;guo[1].junli=250;guo[1].zhengzhi=1850;guo[1].tizhi=2;
	guo[2].name="Greg";guo[2].guoli=1000;guo[2].tudi=83;guo[2].jingji=550;guo[2].bingli=200;guo[2].junli=200;guo[2].zhengzhi=1800;guo[2].tizhi=2;
	guo[3].name="Linda";guo[3].guoli=1000;guo[3].tudi=76;guo[3].jingji=500;guo[3].bingli=150;guo[3].junli=150;guo[3].zhengzhi=1750;guo[3].tizhi=2;
	guo[4].name="June";guo[4].guoli=1000;guo[4].tudi=76;guo[4].jingji=500;guo[4].bingli=150;guo[4].junli=150;guo[4].zhengzhi=1750;guo[4].tizhi=2;
	guo[5].name="Krystal";guo[5].guoli=1000;guo[5].tudi=76;guo[5].jingji=500;guo[5].bingli=150;guo[5].junli=150;guo[5].zhengzhi=1750;guo[5].tizhi=2;
	guo[6].name="Bella";guo[6].guoli=1000;guo[6].tudi=76;guo[6].jingji=500;guo[6].bingli=150;guo[6].junli=150;guo[6].zhengzhi=1750;guo[6].tizhi=2;
	guo[7].name="Lesley";guo[7].guoli=1000;guo[7].tudi=76;guo[7].jingji=500;guo[7].bingli=150;guo[7].junli=150;guo[7].zhengzhi=1750;guo[7].tizhi=2;
	guo[8].name="Emma";guo[8].guoli=1000;guo[8].tudi=76;guo[8].jingji=500;guo[8].bingli=150;guo[8].junli=150;guo[8].zhengzhi=1750;guo[8].tizhi=2;
	guo[9].name="张校";guo[9].guoli=1000;guo[9].tudi=600;guo[9].jingji=688;guo[9].bingli=300;guo[9].junli=300;guo[9].zhengzhi=2750;guo[9].tizhi=2;
	guo[10].name="郦校";guo[10].guoli=1000;guo[10].tudi=600;guo[10].jingji=688;guo[10].bingli=300;guo[10].junli=300;guo[10].zhengzhi=2750;guo[10].tizhi=2;
	for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++)if(i==j)tu[i][j]=0;
	else if(i==9||j==9||i==10||j==10)tu[i][j]=1e9;else tu[i][j]=100+rand()%512;
	for(int i=1;i<=cnt;i++)
	for(int j=1;j<=cnt;j++)
	for(int k=1;k<=cnt;k++){
		if(i==j||j==k||i==k)continue;
		tu[j][k]=min(tu[j][i]+tu[i][k],tu[j][k]);
	}
	for(i=1;i<=cnt;i++){
		xg[i]=guo[i].guoli;
		xb[i]=guo[i].bingli;
		xj[i]=guo[i].junli;
		xJ[i]=guo[i].jingji;
		xt[i]=guo[i].tudi;
		xZ[i]=guo[i].zhengzhi;
		xT[i]=guo[i].tizhi;
		xz[i]=guo[i].zhen;
		sh[i]=0;du[i]=0;bj[i]=i;gg[i]=1;si[i]=0;
		guo[i].tu="land";
	}Y=2018;M=1;W=0;YY=MM=0,WW=7;
	}
	if(z1.empty())z1='_';if(z2.empty())z2='_';
	printf("           选择%s\n\n",orz.c_str());
	for(int i=1;i<=cnt;i++)printf("        %d、%s%c",i,guo[i].name.c_str(),cnt<60||i%5==0?10:32);
	clc:puts("1P");
	scanf("%d",&p1);
	while(p1<=0||p1>cnt)puts("1P不合法"),scanf("%d",&p1);
	if(dr)p2=0;
	else{
	puts("2P");
	scanf("%d",&p2);
	while(p2<=0||p2>cnt)puts("2P不合法"),scanf("%d",&p2);
	}
	if(p1==p2){puts("1P2P一样");goto clc;}
	if(tt==19&&p1!=cnt&&p2!=cnt)--cnt,tu[184][33]=1;
	else if(tt==19){
		int _=0;printf("Weaken who?");while(_<1||_>235)scanf("%d",&_);
		guo[236].tu=guo[_].tu,guo[_].tu="妖土",guo[236].name=guo[_].name,guo[_].name="???";
		if(_!=184)tu[184][33]=1;
	}
	while(1){
		js=md[1]=md[2]=md[0]=md[3]=0;
		for(int i=1;i<=cnt;i++)if(!si[i])++md[xz[i]],++js;
		if(!typ)md[1]++,md[2]++,md[0]++,md[3]++;
		player1_win=si[p1]?0:xz[p1]==(3-typ)&&md[typ]==0||md[3-typ]==0;
		player2_win=si[p2]?0:xz[p2]==(3-typ)&&md[typ]==0||md[3-typ]==0;
		if(!typ){
			player1_win=player2_win=1;
			for(int i=1;i<=cnt;i++)if(i!=p1&&!fr[i][p1]&&!si[i])player1_win=0;
			for(int i=1;i<=cnt;i++)if(i!=p2&&!fr[i][p2]&&!si[i])player2_win=0;
		}
		if(T==7){
			if(si[1]&&!si[2]){
				player1_win=p1==2||p1==3;player2_win=p2==2||p2==3;
			}
			if(si[2]&&!si[1]){
				player1_win=p1==1;player2_win=p2==1;
				if(p1+p2==5||dr&&p1!=1){cls;
printf("\n\n\n                  %s方%s全部沦陷！！！  游戏结束！！！\n\n\n\n                    ",
dr?"我":"1P、2P",guo[2].tu.c_str());Sleep(slp*6);break;
				}
			}
		}
		if(dr)player2_win=0;
		if(player1_win||player2_win)cls;
		if(player1_win&&player2_win){
			printf("                    恭喜1P%s,2P%s胜利！！！",guo[p1].name.c_str(),guo[p2].name.c_str());Sleep(slp*6);break;
		}
		if(player2_win){
			printf("                    恭喜2P%s胜利！！！",guo[p2].name.c_str());Sleep(slp*6);break;
		}
		if(player1_win&&!dr){
			printf("                    恭喜1P%s胜利！！！",guo[p1].name.c_str());Sleep(slp*6);break;
		}
		if(player1_win&&dr){
			printf("                    恭喜%s胜利！！！",guo[p1].name.c_str());Sleep(slp*6);break;
		}if(typ)printf("%d %d\n",md[1],md[2]),Sleep(slp*2);cls;
		for(int i=1;i<=cnt;i++)xg[i]+=up(i);Y+=YY;M+=MM;W+=WW;
		if(M>12)Y++,M-=12;
		if(W>(ooo[M]+(Y%4==0&&M==2)))W-=(ooo[M]+(Y%4==0&&M==2)),M++;
		if(M>12)Y++,M-=12;
		if(si[p1])goto pp1;
		sj(p1);if(T==1)sj1(p1);if(T==3)sj2(p1);if(T==4)sj3(p1);if(T==23)sj4(p1);
		pp0:printf("               公元   %d 年      %d月 %d日  \n\n\n\n          %s",Y,M,W,guo[p1].name.c_str());
		Sleep(slp*2);while(!jc(p1));
		pp1:if(si[p2])goto pp2;
		if(!dr)
		printf("               公元   %d 年      %d月 %d日  \n\n\n\n          %s",Y,M,W,guo[p2].name.c_str());
		if(!dr){if(T==1)sj1(p2);if(T==3)sj2(p2);if(T==4)sj3(p2);if(T==23)sj4(p2);Sleep(slp*2);while(!jc(p2));}
		pp2:for(int i=1;i<=cnt;i++)if(i!=p1&&i!=p2&&!si[i]){
			jc(i);if(lo)break;
		}if(lo)break;
	}
}

