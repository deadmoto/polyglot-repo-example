import io.grpc.ManagedChannel;
import io.grpc.ManagedChannelBuilder;
import proto.EchoProto;
import proto.EchoProto.EchoRequest;
import proto.EchoProto.EchoResponse;
import proto.EchoServiceGrpc;
import proto.EchoServiceGrpc.EchoServiceBlockingStub;

public class EchoClient {

    public static void main(String[] args) {
        EchoRequest request = EchoRequest.newBuilder()
                .setText("Hello world!")
                .build();
        ManagedChannel channel = ManagedChannelBuilder.forAddress("127.0.0.1", 54321)
                .usePlaintext()
                .build();
        EchoServiceBlockingStub stub = EchoServiceGrpc.newBlockingStub(channel);
        EchoResponse response = stub.echo(request);
        System.err.println(response.getText());
    }

}
