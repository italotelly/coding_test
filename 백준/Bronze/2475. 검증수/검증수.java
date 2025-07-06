import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력용 BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 입력 줄 받아오기
        String[] input = br.readLine().split(" ");
        int sum = 0;

        // 각 숫자를 제곱해서 더하기
        for (int i = 0; i < 5; i++) {
            int num = Integer.parseInt(input[i]);
            sum += num * num;
        }

        // 검증수 출력
        System.out.println(sum % 10);
    }
}
