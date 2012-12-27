

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

function onLogin() {

	$("#flogin").hide();
	$("#mbody").show();

	
	$(".tab_local").hide(); //Hide all content
	$(".tab_usr").hide(); //Hide all usr
	$("ul.tabs li:first").addClass("active").show(); //Activate first tab
	$(".tab_local:first").show(); //Show first tab content
	$(".width_3_quarter").hide();
	$(".width_full").hide();


	$("#local").show();
	$("#resOK").hide();
	
	getRoot();



}


function onLogout()
{
	$("#mbody").hide();
	$("#flogin").show();
	
	
}

function onUpgrade(){
	var fname = document.getElementById("filename").value;
	var url = "cgi-bin/post.cgi";
	   //alert(url.toString());
	   request.open("POST", url, true);
	   request.onreadystatechange = updateUpgrade;
	   request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;charset=gb2312");
	   var chr = "phone=" + fname.toString();
	   request.send(chr.toString());
	   alert("chr is :" + chr.toString());
}

function updateUpgrade(){
	if (request.readyState == 4) {
	  //alert("status is fewe");
       if (request.status == 200) {
         var response = request.responseText.split("|");
         alert("aa:" + response[0].toString());	 

         
		   
       } else
         alert("status is " + request.status);
     }
}


function operate2(){
	$("#submitForm").ajaxSubmit({  
                    type: 'post',  
                    dataType:"xml",
                    url: "cgi-bin/post.cgi" ,  
                    success: function(data){  
                        alert( "success");  
                        alert(data);
                          
                    },  
                    error: function(XmlHttpRequest, textStatus, errorThrown){  
                        alert( "error");  
                    }  
                });  
                
                return false;
}
 
function operate() {
    // jquery 表单提交
    $("#submitForm").ajaxSubmit(function(message) {
          // 对于表单提交成功后处理，message为提交页面operation.htm的返回内容
          alert(message.toString());
       });
     
    return false; // 必须返回false，否则表单会自己再做一次提交操作，并且页面跳转
}


function doUpload() {
	// 上传方法
	$.upload({
			// 上传地址
			url: '/upload', 
			// 文件域名字
			fileName: 'filedata', 
			// 其他表单数据
			params: {name: 'pxblog'},
			// 上传完成后, 返回json, text
			dataType: 'json',
			// 上传之前回调,return true表示可继续上传
			onSend: function() {
					return true;
			},
			// 上传之后回调
			onComplate: function(data) {
					alert(data);
			}
	});
}
