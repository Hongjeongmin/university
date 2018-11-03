<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!-- menu.jsp -->
<html>
<head>
<meta charset="UTF-8">
<title>메뉴화면이에요~</title>
</head>
<%
	request.setCharacterEncoding("UTF-8");
	String id = (String)session.getAttribute("id");
%>

<body style="background-color:yellow">

<h1>MENU</h1>
<hr>
<font color="blue"><%=id%></font>님, 안녕하세요!<br>
<hr>

<ul>
	<li><a href= "notebook.jsp">노트북</a>
	<li><a href= "car.jsp">자동차</a>
	<li><a href= "game.jsp">게임</a>
	<li><a href= "bsket.jsp">장바구니</a>
	<li><a href= "logout.jsp">로그아웃</a>
</ul>

</body>
</html>