%%% Reads the Catalan number from CMD
prompt = "List Catalan no. up to: ";
N = input(prompt);

tic
for j = 1:N
    printf("j = %i, C_j = %i", j, catalanNumber(j));
end
toc
