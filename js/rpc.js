

function getRoot() {
	   var name = {id:1,jsonrpc:"2.0",method:"getroot"};
	   var encoded = $.toJSON( name );
	   var url = "cgi-bin/post.cgi";
	   //alert(url.toString());
	   request.open("POST", url, true);
	   request.onreadystatechange = updateRoot;
	   request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;charset=gb2312");
	   var chr = "phone=" + encoded.toString();
	   request.send(chr.toString());
	   //alert("chr is :" + chr.toString());
	   
   }
   
   function updateRoot() {
      if (request.readyState == 4) {
	  //alert("status is fewe");
       if (request.status == 200) {
         var response = request.responseText.split("|");
         //alert("aa:" + response[0].toString());	 

         var obj = jQuery.parseJSON(response[0].toString());
         var name = (obj.pam.base.name.toString());
         var lan = obj.pam.base.lan.toString();
         document.getElementById("macname").value = name;
         document.getElementById("maclan").value = lan;
         $("#resOK").show();
         $("#resOK").hide(2000);
		   
       } else
         alert("status is " + request.status);
     }
   }
