<%@ page language="java" contentType="text/html;
charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<%
		ArrayList<String> arr =  (ArrayList<String>)session.getAttribute("arr");
		String str = request.getParameter("contents");
		arr.add(str);
		//session.setAttribute("arr", arr);
		String[] dede = request.getParameterValues("dede");
		if(dede !=null)
		{
			for(String de : dede)
			{
				arr.remove(Integer.parseInt(de));
			}	
		}
		session.setAttribute("arr",arr);
 	%>
	<h2>지금까지의 의견들</h2><p>
	<form method="post" action="c.jsp">
		<table border="1">
				<tr>
					<th>의견</th><th>삭제</th>
				</tr>
				<%
				for(int i=0;i<arr.size();i++)
				{
					if(arr.get(i) !=null){
			%>
					<tr>
						<td><%= arr.get(i) %></td><td><input type="checkbox" name="dede" value="<%=i %>"></td>
					</tr>
			<%  }} %>
		</table>
		<input type="submit" value="삭제하기">
		<p>

	</form>
		하고 싶은 말을 자유롭게!
		<form method="post" action="c.jsp">
		<textarea rows="5" cols="30" name="contents"></textarea>
		<input type="submit" value="전송">
		</form>
</body>
</html>