<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	request.setCharacterEncoding("UTF-8");
	String comment = request.getParameter("comment");
	session.setAttribute("comment",comment);
	session.setMaxInactiveInterval(60*60);
%>
<h2>설문 조사 결과!!!</h2>
<%
	String id = (String) session.getAttribute("id");
	String dr = (String) session.getAttribute("dr");
	String car = (String) session.getAttribute("car");
%>

이름 : <%= id %><br>
좋아하는 음료: <%= dr %><br>
좋아하는 차 : <%= car %><br>
좋아하는 쇼미더머니 대사: <%= comment %><p>
과제끝!


</body>
</html>