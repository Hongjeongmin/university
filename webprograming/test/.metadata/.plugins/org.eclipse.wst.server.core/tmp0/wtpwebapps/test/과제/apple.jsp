<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
.... apple.jsp 시작 <p>
<jsp:forward page="carrot.jsp">
	<jsp:param name = "iam" value="apple"/>
	<jsp:param name = "color" value="red/>
</jsp:forward>
...... apple.jsp 끝 <p>
</body>
</html>