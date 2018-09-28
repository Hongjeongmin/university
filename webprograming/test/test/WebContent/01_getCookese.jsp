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
	Cookie c = new Cookie("id","james");
	c.setMaxAge(7*24*60*60);
	response.addCookie(c);
	
	response.addCookie(new Cookie("pwd","1234"));
	response.addCookie(new Cookie("age","21"));
%>
<h3>쿠기 설정 했다~</h3>

</body>
</html>