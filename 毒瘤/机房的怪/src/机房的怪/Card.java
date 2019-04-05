package �����Ĺ�;

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
				master.sendWarn("gj ײ gj ����ը");
				target.master.sendWarn("gj ײ gj ����ը");
				alive=false;
				target.alive=false;
				master.addHp(-20);
				target.master.addHp(-20);
				return;
			}
			if(Math.random()>0.1)return;
			target.hp/=2;
			hp/=2;
			master.sendWarn("gj ��a��ʧ�� һ�� ����");
			target.master.sendWarn(target.name+" a���˷��� һ�� ����");
		}else if(name.equals("syy")) {
			if(Math.random()>0.25)return;
			hp+=5;
			master.addHp(10);
			master.sendWarn("syy �������������ȫ�� HP");
		}else if(name.equals("yyh")) {
			if(Math.random()>0.05)return;
			if(target.name=="xkx") {
				target.hp-=15;
				master.sendWarn("������ xkx �� yyh ��ˮ��");
				target.master.sendWarn("xkx �ܵ� ��ˮ��yyh �� 15 ���˺�");
			}else {
				target.hp-=30;
				master.sendWarn("yyh ֱ��Ůװ");
				target.master.sendWarn(target.name+" �� Ůװyyh ���� �ܵ� 30 ���˺�");
			}
		}else if(name.equals("xkx")) {
			if(Math.random()>0.25)return;
			if(target.name=="xkx") {
				master.sendWarn("�� xkx ������ xkx �������Ժ�");
				target.master.sendWarn("�� xkx ������ xkx �������Ժ�");
			}else {
				target.dps/=2;
				if(target.dps==0)target.dps=1;
				master.sendWarn("xkx ʹ���Ȼ�");
				target.master.sendWarn(target.name+"�� xkx �Ȼ󣬹���������һ��");
			}
		}else if(name.equals("dfc")) {
			if(Math.random()>0.1)return;
			if(target.name=="gj") {
				target.hp=0;
				hp+=10;
				master.sendWarn("dfc ̧gj֮�������泩����10��hp");
				target.master.sendWarn("gj �ܵ�����˳���");
			}else {
				if(Math.random()<0.2) {
					master.sendWarn("dfc �� "+target.name+" ����Ϊgj");
					target.master.sendWarn(target.name+" ������Ϊgj");
					target.name="gj";
					target.fullHp=40;
				}else {
					master.sendWarn("dfc ��"+target.name+"����ʧ�ܣ��Բ� 3 ��");
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
			master.sendWarn("wky ���ֵ���,��������,���� "+tot+" ��");
		}else if(name.equals("ztn")) {
			if (Math.random()<0.25) {
				master.sendWarn("ztn ���˱�������,AK��");
				dps+=2;
				hp-=5;
			}
			if (Math.random()<0.25) {
				master.sendWarn("ztn ����AD��,hp++");
				hp+=10;
			}
		}else if(name.equals("ljy")) {
			if (Math.random()<0.1) {
				master.sendWarn("ljy ���˷���hp++");
				hp+=(int)((fullHp-hp)/10);
			}
			if (Math.random()<0.1) {
				master.sendWarn("ljy ʹ�ü�����ѹ��ѪԽ�߹���Խ�ߣ�");
				target.hp-=(int)(hp/20);
			}
		}else if(name.equals("pfy")) {
			if(Math.random()>0.5) return;
			if(Math.random()>0.5) {
				master.sendWarn("pfy ����̫�hp--");
				hp-=10;
			}else {
				master.sendWarn("pfy �����Ϻã�hp++");
				hp+=10;
			}
			if(Math.random()>0.01) return;
			master.sendWarn("pfy �����ˣ���ɱ!!!");
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
