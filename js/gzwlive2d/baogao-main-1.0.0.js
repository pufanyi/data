window.onload=function(){
	let live=new Live(document.getElementById('live'));
	(function anim(){
		live.paint();
		setTimeout(anim,10);
	})();
}