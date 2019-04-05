package 机房的怪;

import java.awt.Color;
import java.awt.Graphics;

public class Card {
	private Master master;
	private String name;
	private int lastHp,hp,fullHp,lastTargetPlace;
	private int dps;
	private boolean alive,isnew;
	public Card(Master _master,String _name) {
		master=_master;
		name=_name;
		isnew=true;
		if(name.equals("gj")) {
			lastHp=hp=fullHp=40;
			dps=3;
		}else if(name.equals("syy")) {
			lastHp=hp=fullHp=100;
			dps=4;
		}else if(name.equals("yyh")) {
			lastHp=hp=fullHp=150;
			dps=8;
		}else if(name.equals("xkx")) {
			lastHp=hp=fullHp=80;
			dps=3;
		}else if(name.equals("dfc")) {
			lastHp=hp=fullHp=200;
			dps=9;
		}else if(name.equals("wky")) {
			lastHp=hp=fullHp=111;
			dps=9;
		}else if(name.equals("ztn")) {
			lastHp=hp=fullHp=111;
			dps=8;
		}else if(name.equals("ljy")) {
			lastHp=hp=fullHp=250;
			dps=1;
		}else if(name.equals("pfy")) {
			lastHp=hp=fullHp=130;
			dps=5;
		}
		alive=true;
		lastTargetPlace=-1;
	}
	public void print(int x,int y,Graphics g,boolean isLeft) {
		if(isnew) {
			g.setColor(Color.blue);
			g.drawString(name+"  new",x,y);
		}else{
			g.setColor(Color.black);
			g.drawString(name,x,y);
		}
		y+=5;
		g.setColor(Color.black);
		g.fillRect(x, y, fullHp+4, 10);
		g.setColor(Color.GREEN);
		g.fillRect(x+2,y+2,hp,6);
		if(lastHp>hp) {
			g.setColor(Color.RED);
			g.fillRect(x+2+hp,y+2,lastHp-hp,6);
		}else {
			g.setColor(Color.YELLOW);
			g.fillRect(x+2+lastHp,y+2,hp-lastHp,6);
		}
		if(!isnew) {
			g.setColor(Color.blue);
			if(isLeft) {
				g.drawLine(x+300, y-2,x+400, y-2+lastTargetPlace*30);
				g.drawLine(x+300, y+2,x+400, y+2+lastTargetPlace*30);
				g.fillOval(x+400, y-4+lastTargetPlace*30,8,8);
			}else {
				g.drawLine(x-40, y-2, x-140, y-2+lastTargetPlace*30);
				g.drawLine(x-40, y+2, x-140, y+2+lastTargetPlace*30);
				g.fillOval(x-144, y-4+lastTargetPlace*30,8,8);
			}
		}
	}
	public void attack(Card target,int targetPlace) {
		isnew=false;
		lastTargetPlace=targetPlace;
		if(alive) {
			if(target==null)return;
			if(target.hp<=0)return;
			target.hp-=dps;
			magic(target);
		}
	}
	public String getName() {
		return name;
	}
	public void testAlive() {
		if(hp<=0)alive=false;
		if(hp>fullHp)hp=fullHp;
	}
	public void setLastHp() {
		lastHp=hp;
	}
	public boolean isalive() {
		return alive;
	}
	private void magic(Card target) {
		if(name.equals("gj")) {
			if(target.name=="gj") {
				if(Math.random()>0.5)return;
				master.sendWarn("gj 撞 gj 引起爆炸");
				target.master.sendWarn("gj 撞 gj 引起爆炸");
				alive=false;
				target.alive=false;
				master.addHp(-20);
				target.master.addHp(-20);
				return;
			}
			if(Math.random()>0.1)return;
			target.hp/=2;
			hp/=2;
			master.sendWarn("gj 找a损失了 一半 体力");
			target.master.sendWarn(target.name+" a人浪费了 一半 体力");
		}else if(name.equals("syy")) {
			if(Math.random()>0.25)return;
			hp+=5;
			master.addHp(10);
			master.sendWarn("syy 活在梦里，补充了全队 HP");
		}else if(name.equals("yyh")) {
			if(Math.random()>0.05)return;
			if(target.name=="xkx") {
				target.hp-=15;
				master.sendWarn("遇到了 xkx ， yyh 放水了");
				target.master.sendWarn("xkx 受到 放水的yyh 的 15 点伤害");
			}else {
				target.hp-=30;
				master.sendWarn("yyh 直播女装");
				target.master.sendWarn(target.name+" 被 女装yyh 暴击 受到 30 点伤害");
			}
		}else if(name.equals("xkx")) {
			if(Math.random()>0.25)return;
			if(target.name=="xkx") {
				master.sendWarn("当 xkx 遇上了 xkx ，握手言和");
				target.master.sendWarn("当 xkx 遇上了 xkx ，握手言和");
			}else {
				target.dps/=2;
				if(target.dps==0)target.dps=1;
				master.sendWarn("xkx 使用魅惑");
				target.master.sendWarn(target.name+"被 xkx 魅惑，攻击力减少一半");
			}
		}else if(name.equals("dfc")) {
			if(Math.random()>0.1)return;
			if(target.name=="gj") {
				target.hp=0;
				hp+=10;
				master.sendWarn("dfc 抬gj之后心情舒畅，加10点hp");
				target.master.sendWarn("gj 受到打击退场了");
			}else {
				if(Math.random()<0.2) {
					master.sendWarn("dfc 把 "+target.name+" 改名为gj");
					target.master.sendWarn(target.name+" 被改名为gj");
					target.name="gj";
					target.fullHp=40;
				}else {
					master.sendWarn("dfc 对"+target.name+"改名失败，自残 3 点");
					hp-=3;
				}
			}
		}else if(name.equals("wky")) {
			int tot=1;
			hp+=3;
			while(Math.random()<0.5) {
				target.hp-=dps;
				++tot;
				hp+=3;
			}
			master.sendWarn("wky 保持单身,发动技能,连击 "+tot+" 次");
		}else if(name.equals("ztn")) {
			if (Math.random()<0.25) {
				master.sendWarn("ztn 吃了爆蛋鱿鱼,AK了");
				dps+=2;
				hp-=5;
			}
			if (Math.random()<0.25) {
				master.sendWarn("ztn 喝了AD钙,hp++");
				hp+=10;
			}
		}else if(name.equals("ljy")) {
			if (Math.random()<0.1) {
				master.sendWarn("ljy 吃了饭，hp++");
				hp+=(int)((fullHp-hp)/10);
			}
			if (Math.random()<0.1) {
				master.sendWarn("ljy 使用技能碾压（血越高攻击越高）");
				target.hp-=(int)(hp/20);
			}
		}else if(name.equals("pfy")) {
			if(Math.random()>0.5) return;
			if(Math.random()>0.5) {
				master.sendWarn("pfy 运气太差，hp--");
				hp-=10;
			}else {
				master.sendWarn("pfy 运气较好，hp++");
				hp+=10;
			}
			if(Math.random()>0.01) return;
			master.sendWarn("pfy 进洞了，秒杀!!!");
			target.alive=false;
		}
	}
	public void addHp(int dHp) {
		hp+=dHp;
	}
	public String toString() {
		return name+" "+hp+" "+fullHp+" "+dps;
	}
}
