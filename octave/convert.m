#!/usr/bin/octave -qf

init_setting;

sentence1 = "他吃烤白薯";
temp = input_number - size(double(sentence1))(1,2);
samplelist = [double(sentence1),zeros(1,temp)];

expectlist=[1 1 0 0 0 0 0 0 0 0];

fid = fopen("exercise.txt","r");
while ~feof(fid)

    sentence = fgetl(fid);

    temp = input_number - size(double(sentence))(2);
    vec = [double(sentence),zeros(1,temp)];
    samplelist = cat(1,samplelist,vec);

    sen = double(sentence);
    i = 4;
    output = [];

    while i< size(sen)(2)
        if sen(i) == 32
            sen = [sen(1:3) sen(5:size(sen)(2))];
            value = 1;
        else
            value = 0;
        end
        output = cat(2,output,value);
        i = i + 3;
    end

    temp = output_number - size(output)(2);
    vec = [output,zeros(1,temp)];
    expectlist = cat(1,expectlist,vec);
end
fclose(fid);

%fid = fopen("input.dat","wt");
%fwrite(fid,samplelist);
%fprintf(fid,"%g\r\n",samplelist);
%fclose(fid);

dlmwrite('input.dat',samplelist);
dlmwrite('expect.dat',expectlist);

input('转换完毕...');
