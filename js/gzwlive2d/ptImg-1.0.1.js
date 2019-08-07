let PtImg;
PtImg=function(filename){
	let img;
	let canvas;
	let ctx;
	img=document.createElement('img');
	img.src=filename;
	let ans=[];
	let imgload=false;
	img.onload=function(){
		imgload=true;
		canvas=document.createElement('canvas');
		canvas.width=img.width;
		canvas.height=img.height;
		ctx=canvas.getContext('2d');
		ctx.clearRect(0,0,canvas.width,canvas.height);
		ctx.drawImage(img,0,0);
	}
	this.cLoad=function(){
		if(ans.length>=img.height*img.width)return;
		if(imgload){
			let time=new Date().getTime();
			while(new Date().getTime()-time<5){
				let g=ans.length;
				let y=g%img.height;
				let x=(g-y)/img.height;
				let v=ctx.getImageData(x,y,1,1).data;
				ans[g]=((v[0]*256+v[1])*256+v[2])*256+v[3];
			}
		}
	}
	this.getColor=function(i,j){
		i=parseInt(i);
		j=parseInt(j);
		if(i<0||i>=img.width||j<0||j>=img.height)return 0;
		let g=i*img.height+j;
		if(ans[g]!=null)return ans[g];
		else return 0;
	}
}