<%@ page language="java" contentType="text/html; charset=EUC-KR"
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
	%>
	나는 <%= request.getParameter("id") %>의 비번을 알고 있다.<br>
	<%= request.getParameter("pw") %> 맞지? 으허허헣!!!
</body>
</html>