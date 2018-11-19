<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%
	String id = (String)session.getAttribute("id");
	session.invalidate();
%>
<h2>로그아웃하셧습니다. <FONT COLOR=BLUE><%= id %></FONT>님, 또 방문해 주세요!</h2>

첫 화면으로 가시려면 아래 그림을 클릭해 주세요~<br>
<a href="login.jsp"><img src="D:\photo\image.jpg" width="300" height="360" alt="뭔가 그냥 예의상"></a>
</body>
</html>