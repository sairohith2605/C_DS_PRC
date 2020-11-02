package gb;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ptserve extends HttpServlet
{
	public void service(HttpServletRequest req , HttpServletResponse res) throws IOException
	{
		int i = Integer.parseInt(req.getParameter("num1"));
		PrintWriter out = res.getWriter();
		
		out.println(i);
	}
}
