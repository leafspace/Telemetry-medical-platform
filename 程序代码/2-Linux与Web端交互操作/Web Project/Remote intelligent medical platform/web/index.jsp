<%--
  Created by Visual Studio Code.
  User: Administrator
  Date: 2017/5/7
  Time: 22:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
	<head>
		<title>智能医疗信息管理系统</title>
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<script type="application/x-javascript"> addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false); function hideURLbar(){ window.scrollTo(0,1); } </script>
		<link rel="shortcut icon" href="icon.ico"> 
		<link href="css/style.css" rel="stylesheet" type="text/css" media="all" />
		<script src="js/jquery-1.11.1.min.js"></script>
		<script>
            $(function(){
                setInterval(refresh, 5000);
                function refresh(){
                    $('#content').html("");
                    var xmlhttp;
                    if (window.XMLHttpRequest) {                     // code for IE7+, Firefox, Chrome, Opera, Safari
                        xmlhttp = new XMLHttpRequest();
                    }
                    else {                                           // code for IE6, IE5
                        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
                    }
                    xmlhttp.onreadystatechange = function() {
                        if (xmlhttp.readyState==4 && xmlhttp.status==200) {
                            document.getElementById("content").innerHTML = xmlhttp.responseText;
                        }
                    }
                    xmlhttp.open("POST", "ajaxGetData.do", true);
                    xmlhttp.send();
                }

                setInterval(refreshNumber, 5000);
                function refreshNumber(){
                    $('#messageNumber').html("");
                    var xmlhttp;
                    if (window.XMLHttpRequest) {                     // code for IE7+, Firefox, Chrome, Opera, Safari
                        xmlhttp = new XMLHttpRequest();
                    }
                    else {                                           // code for IE6, IE5
                        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
                    }
                    xmlhttp.onreadystatechange = function() {
                        if (xmlhttp.readyState==4 && xmlhttp.status==200) {
                            document.getElementById("messageNumber").innerHTML = xmlhttp.responseText;
                        }
                    }
                    xmlhttp.open("POST", "ajaxGetDataNumber.do", true);
                    xmlhttp.send();
                }
            })
		</script>
	</head>
	<body>
		<div class="main">
			<h1>患者医疗信息</h1>
			<div class="account">
				<div class="account-info">
					<div class="account-top">
						<div class="account-top-left">
							<img src="images/img1.jpg" alt="">
						</div>
						<div class="account-top-right">
							<h2>病人A </h2>
							<p>住院部D & 7-207</p>
						</div>
						<div class="clear"> </div>
					</div>
					<div class="account-bottom">
						<div class="tabs">
							<nav> 
								<a><span> </span>医嘱信息 <i id="messageNumber"></i></a>
								<a><span class="icon1"></span>星标医嘱</a> 
								<a><span class="icon2"></span>医嘱备份</a>
								<a><span class="icon3"></span>待处理医嘱</a>
								<a><span class="icon4"></span>已删除医嘱</a>
							</nav>
							<div id="content" class="content">

							</div>

							<div class="content">
							</div>

							<div class="content">
							</div>

							<div class="content">
							</div>

							<div class="content">
							</div>
						</div>
						<div class="options">
							<select tabindex="4" class="dropdown">
								<option value="" class="label">操作</option>
								<option value="1">操作1</option>
								<option value="2">操作2</option>
								<option value="3">操作3</option>
							</select>
						</div>
					</div>
				</div>
			</div>
		</div>
		<div class="copyright">
			<p> &copy; 2017 智慧医疗信息管理系统 & 语音识别模块 | 数据来源 <a href="#" >leafspace</a></p>
		</div>

		<script>
			$(function() {
			$('.tabs nav a').on('click', function() {
				show_content($(this).index());
			});
			
			show_content(0);

			function show_content(index) {
				// Make the content visible
				$('.tabs .content.visible').removeClass('visible');
				$('.tabs .content:nth-of-type(' + (index + 1) + ')').addClass('visible');

				// Set the tab to selected
				$('.tabs nav a.selected').removeClass('selected');
				$('.tabs nav a:nth-of-type(' + (index + 1) + ')').addClass('selected');
			}
			});
		</script>
		<script type="text/javascript">

		var _gaq = _gaq || [];
		_gaq.push(['_setAccount', 'UA-36251023-1']);
		_gaq.push(['_setDomainName', 'jqueryscript.net']);
		_gaq.push(['_trackPageview']);

		(function() {
			var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
			ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
			var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
		})();
		</script>
	</body>
</html>