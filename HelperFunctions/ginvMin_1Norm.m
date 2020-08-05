% Author: Einar Ueland (heavily based on the work of Ivan Dokmani?, Rémi Gribonval
% https://github.com/doksa/altginv)
% email: einar.s.ueland@gmail.com
% September 2019;
% If used, please cite Ivan Dokmani?/Rémi Gribonval through
%https://github.com/doksa/altginv   


function X = ginvMin_1Norm(A)
MAX_ITER = 1000;
RELTOL   = 1e-5;

[m, n] = size(A);
proxfcn=@(V,lambda) wthresh(V, 's', lambda);

% These things probably only work for fat matrices
if m > n
    error('A should be fat!');
end
N      = null(A);
Proj_N = N*N';
B      = pinv(A);

    U = zeros(n, m);
    Z = zeros(n, m);
    X = zeros(n, m);

    lambda = .1;
    for k = 1:MAX_ITER
        % Update X, Z, and U
        X = B + Proj_N*(Z - U);
        Z_old = Z;
        Z = feval(proxfcn, X + U, lambda);

        % Fix this
        if norm(Z_old - Z, 'fro') / norm(Z_old, 'fro') < RELTOL
            break;
        end

        U = U + X - Z;
    end

if k == MAX_ITER
%     fprintf('Warning: MAXITER reached. Relative error is %f. Norm is %s.\n', norm(Z_old - Z, 'fro') / norm(Z_old, 'fro'), norm_name);
end


