<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<%
out.print("1에서 10까지 합은?<br>");
int i,sum =0;
for(i=1;i<=10;i++)
{
	sum +=i;
}
out.print(sum+"입니다");
%>

</head>
<body>

</body>
</html>