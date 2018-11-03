<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!-- check_id.jsp -->
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
<%
	request.setCharacterEncoding("UTF-8");
	String id = request.getParameter("id");
	String[] members = {"a","b","c","d","e","wjdals0471"};
	
	String pw = request.getParameter("pw");
	String[] members_pw = {"1","2","3","4","5","wjdals12"};
	int check=0;
	int money=0;
	int input_cnt=0;
	int output_cnt=0;
	
	for(int m=0; m<6;m++)
	{
		if(members[m].equals(id) && members_pw[m].equals(pw))
		{
			session.setAttribute("id",id);
			session.setMaxInactiveInterval(60*60);
			response.sendRedirect("menu.jsp");	
		}
		if(members[m].equals(id))
		{
			check=1;
			break;
		}
	}

	
%>
<%if(check==1){%>
	<script>
	alert("비밀번호가 잘못됨~ 문의전화: 010-8223-0471");
	location.href="login.html";
	</script>
<%}
else if(check==0){%>
<script>
	alert("미등록 아이디입니다~ 문의전화: 010-8223-0471");
	location.href="login.html";
	</script>
<%}%>

</body>
</html>