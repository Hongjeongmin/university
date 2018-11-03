<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!-- logout_id.jsp -->
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
<%
String id = (String)session.getAttribute("id");
long lasttime = session.getLastAccessedTime();
long createdtime = session.getCreationTime();
long time_used  = (lasttime - createdtime) / 1000;

%>
<script>
	alert("로그아웃 되었습니다. <%=id%>님 안녕히 가세요~ 머무른시간!:<%= time_used%> 초");
	<% session.invalidate();%>
	location.href="login.html";
</script>

</body>
</html>