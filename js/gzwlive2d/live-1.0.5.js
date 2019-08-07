let Live;

Live=function(element){
	const WIDTH=300;
	const HEIGHT=400;
	const thisLine=this;
	
	let canvas;
	let mouse;
	let lastPaintTime;
	let ctx;
	
	this.init=function(){
		element.style.position='fixed';
		$(element).width(WIDTH);
		$(element).height(HEIGHT);
		$(element).css('right',0);
		$(element).css('bottom',0);
		canvas=document.createElement('canvas');
		canvas.width=WIDTH;
		canvas.height=HEIGHT;
		element.appendChild(canvas);
		mouse={x:0,y:0};
		ctx=canvas.getContext('2d');
		lastPaintTime=new Date().getTime();
		this.initAct();
	}
	
	let 身;
	let 头;
	let 闭眼头;
	
	let type;
	this.initAct=function(){
		身=new PtImg(imgBase.身);
		头=new PtImg(imgBase.头);
		闭眼头=new PtImg(imgBase.闭眼头);
		type={
			状态:'正常',
			持续时间:0
		};
	}
	this.runAct=function(time){
		身.cLoad();
		头.cLoad();
		闭眼头.cLoad();
		type.持续时间+=time;
		if(type.状态=='正常'){
			if(type.持续时间>300){
				if(Math.random()<0.2){
					type={
						状态:'闭眼',
						持续时间:0,
						头混合:0
					};
				}else if(Math.random()<0.15){
					type={
						状态:'点头',
						持续时间:0,
						头偏移:{
							x:0,
							y:0
						}
					};
				}else{
					type.持续时间=0;
				}
			}
		}else if(type.状态=='点头'){
			if(type.持续时间<400){
				type.头偏移.y+=time*(8/400);
				type.头偏移.x-=time*(3/400);
			}else if(type.持续时间<1000){
				type.头偏移.y-=time*(8/600);
				if(type.头偏移.y<0)type.头偏移.y=0;
				type.头偏移.x+=time*(3/600);
				if(type.头偏移.x>0)type.头偏移.x=0;
			}else{
				type={
					状态:'正常',
					持续时间:0
				};
			}
		}else if(type.状态=='闭眼'){
			if(type.持续时间<1000){
				type.头混合+=time*(1/1000);
				if(type.头混合>1)type.头混合=1;
			}else if(type.持续时间<1500){
			}else if(type.持续时间<2000){
				type.头混合-=time*(1/500);
				if(type.头混合<0)type.头混合=0;
			}else{
				type={
					状态:'正常',
					持续时间:0
				};
			}
		}
	}
	$(window).mousemove(function(event){
		mouse={
			x:event.clientX-$(window).width()+WIDTH,
			y:event.clientY-$(window).height()+HEIGHT
		};
	});
	let p=0;
	this.paint=function(){
		let thisPaintTime=new Date().getTime();
		let deltaPaintTime=thisPaintTime-lastPaintTime;
		this.runAct(deltaPaintTime);
		ctx.clearRect(0,0,WIDTH,HEIGHT);
		
		const recolor=['','0','00','000','0000','00000','000000','0000000','00000000'];
		let drawPoint=function(x,y,color){
			if(color==0)return;
			if(x>=0&&x<WIDTH&&y>=0&&y<HEIGHT){
				color=color.toString(16);
				color='#'+recolor[8-color.length]+color;
				ctx.fillStyle=color;
				ctx.fillRect(x,y,1,1);
			}
		}
		let mix=function(cola,colb,mxb){
			if(cola==colb)return cola;
			let va=[];
			for(let i=0;i<4;i++){
				va.push(cola%256);
				cola-=cola%256;
				cola/=256;
			}
			let vb=[];
			for(let i=0;i<4;i++){
				vb.push(colb%256);
				colb-=colb%256;
				colb/=256;
			}
			let ans=0;
			for(let i=3;i>=0;i--){
				ans=ans*256+Math.round(va[i]*(1-mxb)+vb[i]*mxb);
			}
			return ans;
		}
		for(let x=0;x<WIDTH;x++){
			for(let y=0;y<HEIGHT;y++){
				let dx=Math.abs(mouse.x-x);
				let dy=Math.abs(mouse.y-y);
				let vv=Math.max(0,0.5-Math.sqrt(dx*dx+dy*dy)/200);
				let color=身.getColor(x,y);
				if(color!=0){
					color=mix(color,255,vv);
				}
				drawPoint(x,y,color);
			}
		}
		for(let x=0;x<WIDTH;x++){
			for(let y=0;y<HEIGHT;y++){
				let dx=Math.abs(mouse.x-x);
				let dy=Math.abs(mouse.y-y);
				let vv=Math.max(0,0.5-Math.sqrt(dx*dx+dy*dy)/200);
				let color;
				if(type.状态=='点头'){
					color=头.getColor(x-type.头偏移.x,y-type.头偏移.y);
				}else if(type.状态=='闭眼'){
					color=mix(头.getColor(x,y),闭眼头.getColor(x,y),type.头混合);
				}else{
					color=头.getColor(x,y);
				}
				if(color!=0){
					color=mix(color,255,vv);
				}
				drawPoint(x,y,color);
			}
		}
		lastPaintTime=thisPaintTime;
	}
	this.init();
}