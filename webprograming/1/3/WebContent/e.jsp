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
	int i,sum = 0;
	for(i=1;i<=10;i++){
		sum +=i;
	}
%>
<%=sum %> 입니다~
</body>
</html>