function [ output_args ] = Untitled( input_args )
%UNTITLED �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
A=load('Result.txt');%filename����txt�ĵ�����
[m n]=size(A);%mΪA��������nΪA������
for i=2:n
plot(A(:,1),A(:,i));
hold all
xlabel('Eb/N0');
ylabel('BER');
end

end