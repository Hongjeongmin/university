<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
...... apple.jsp ����<p>
<jsp:forward page="carrot.jsp">
	<jsp:param name = "iam" value="apple"/>
	<jsp:param name = "color" value ="red"/>
</jsp:forward>
...... apple.jsp �� <p>

</body>
</html>