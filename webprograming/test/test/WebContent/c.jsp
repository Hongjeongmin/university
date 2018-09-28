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
	String car = request.getParameter("car");
	session.setAttribute("car",car);
	session.setMaxInactiveInterval(60*60);
%>
<h3>좋아하는 쇼미더머니 대사</h3>
<form method="post" action="find.jsp">
	<input type="text" name="comment"><p>
	<input type="submit" value="제출">
</form>

</body>
</html>