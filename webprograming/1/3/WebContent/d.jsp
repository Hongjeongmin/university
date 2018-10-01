<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%!
	String name[] = {"java","JSP","Android","야호"};
%>
<table border="1">
<% for (int i=0;i<name.length;i++){%>
<tr>
	<td><%=i%></td> <td><%=name[i]%></td>
</tr>
<%}%>	
</table>
</body>
</html>