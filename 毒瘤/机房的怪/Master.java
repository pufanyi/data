package 机房的怪;

import java.awt.Color;
import java.awt.Graphics;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;
import java.util.Vector;

public class Master {
	private String name;
	private Master target;
	private Card[] cards;
	private int[] cardTarget;
	private int cnt;
	@SuppressWarnings("resource")
	private int[] getData() {
		String userVal=toString()+"\n"+target.toString();
		File file = new File("./ai.in");
		if(!file.getParentFile().exists()){
			file.getParentFile().mkdirs();
		}
		Writer out;
		try {
			out=new FileWriter(file);
			out.write(userVal);
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
		try {
			Runtime.getRuntime().exec(name).waitFor();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}catch(InterruptedException e) {
			e.printStackTrace();
			return null;
		}
    	Scanner fin;
    	try {
			fin=new Scanner(new File("./ai.out"));
		} catch (FileNotFoundException e) {
			System.out.println("应用找不到关键文件。");
			return null;
		}
    	int []ans=new int[3];
    	for(int i=0;i<3;i++) {
    		ans[i]=fin.nextInt();
    		if(ans[i]<0)ans[i]=0;
    		if(ans[i]>2)ans[i]=2;
    	}
//    	System.out.println(""+ans[0]+" "+ans[1]+" "+ans[2]);
		return ans;
	}
	public Master(String _name) {
		name=_name;
		cards=new Card[3];
		for(int i=0;i<3;i++) {
			summon(i);
		}
		cnt=0;
	}
	public void set(Master _target) {
		target=_target;
	}
	private void summon(int p) {
		String []alnames= {"pfy","ljy","gj","wky","syy","yyh","dfc","gj","dfc","syy","xkx","yyh","xkx","ztn","gj"};
		int v=(int)(Math.random()*alnames.length);
		String tname=alnames[v];
		Card ncard=new Card(this,tname);
		cards[p]=ncard;
		sendMSG("召唤了 "+tname);
	}
	public void print(int x,int y,Graphics g,boolean isLeft) {
		y+=30;
		x+=20;
		g.setColor(Color.black);
		g.drawString(name+"  (死亡次数："+cnt+")",x,y);
		int ty=y;
		for(int i=0;i<3;i++) {
			ty+=30;
			cards[i].print(x,ty,g,isLeft);
		}
        Long nowTime=java.time.Clock.systemUTC().millis();
        int textH=ty+30;
        int ycnt=0;
        for(int i=0;i<msgs.size();i++) if(nowTime>msgt.get(i)){
        	textH+=20;
        	g.setColor(msgColor.get(i));
        	g.drawString(msgs.get(i), x, textH);
        	ycnt++;
        }
        while(ycnt>20) {
        	msgColor.remove(0);
        	msgs.remove(0);
        	msgt.remove(0);
        	ycnt--;
        }
	}
	public void attack() {
		cardTarget=getData();
		if(cardTarget==null) {
			cardTarget=new int[3];
			for(int i=0;i<3;i++)cardTarget[i]=i;
		}
		for(int i=0;i<3;i++) {
			cards[i].attack(target.cards[cardTarget[i]],cardTarget[i]-i);
		}
	}
	public void setLastHp() {
		for(int i=0;i<3;i++)cards[i].setLastHp();
	}
	public String getName() {
		return name;
	}
	public void testAlive() {
		for(int i=0;i<3;i++) {
			cards[i].testAlive();
			if(!cards[i].isalive()) {
				sendMSG(cards[i].getName()+" 被干了");
				cnt++;
				summon(i);
			}
		}
	}
	public void addHp(int dHp) {
		for(int i=0;i<3;i++) {
			cards[i].addHp(dHp);
		}
	}

	private Vector<Color> msgColor=new Vector<Color>();
	private Vector<String> msgs=new Vector<String>();
	private Vector<Long> msgt=new Vector<Long>();
    public void sendMSG(String msg) {
    	msgColor.add(Color.black);
    	msgs.add(msg);
    	long nowTime=java.time.Clock.systemUTC().millis();
    	if(msgt.size()>30) {
    		nowTime=msgt.lastElement()+10;
    	}else if(!msgt.isEmpty()&&nowTime-msgt.lastElement()<100) {
    		nowTime=msgt.lastElement()+100;
    	}
    	msgt.add(nowTime);
    }
    public void sendWarn(String msg) {
    	msgColor.add(Color.red);
    	msgs.add(msg);
    	long nowTime=java.time.Clock.systemUTC().millis();
    	if(msgt.size()>30) {
    		nowTime=msgt.lastElement()+10;
    	}else if(!msgt.isEmpty()&&nowTime-msgt.lastElement()<100) {
    		nowTime=msgt.lastElement()+100;
    	}
    	msgt.add(nowTime);
    }
    public String toString() {
    	return name+"\n"+cards[0].toString()+"\n"+cards[1].toString()+"\n"+cards[2].toString();
    }
}
