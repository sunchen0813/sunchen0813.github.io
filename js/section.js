(function($){
	$('h1, h2, h3, h4').each(function(i){
		name1 = $(this).attr('id');
		ht = $(this).text();
		grou = ht.match(/[\.A-F0-9]+/g);
		if(grou !== null){
			$.each(grou, function(){
				arr = this.replace(/\./g,'>');
				name1 = name1.replace(this,arr);
			});
		}
		name1 = name1.replace(/\.([A-F0-9][A-F0-9])/g, '%$1').replace(/>/g,'.');
		var host = window.location.href
		if (mw.config.values.wgIsMainPage  ===  true){
		} else {
			$(this).before('<input class="sectionlink" type="text" readonly="readonly" style="background-color:transparent; border: 1px solid #808080; float: right; font-size: 70%;" size="5" onfocus="this.select()" value="' + pagename + '#' + decodeURIComponent(name1).replace('<', '&lt;').replace('>', '&gt;').replace('"', '&quot;').replace("'", "&apos;") + '" />');
		}
	});
})(jQuery);
