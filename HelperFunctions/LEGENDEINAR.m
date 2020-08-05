% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% If used, please cite relevant sources as provided in the readme file. 
%A personal class I have made and use to modify figures to make them nice
%for Printing. Contains much mess.

classdef LEGENDEINAR< dynamicprops
   properties
OldSize=[];
oldGca={}
SCALEFACTOR=1;
   end
   methods
      %%%%%%%%%%%%%%%%%% COLORMETHODS
    function AspectRatio(obj,Aspect)  
        GF=gcf
        movegui(GF,[100,100])
        OP=GF.OuterPosition;
        DX=OP(3)-OP(1);
        DY=OP(4)-OP(2);
        OPN=[OP(1) OP(2) OP(1)+DX*Aspect(1)*obj.SCALEFACTOR OP(2)+DY*Aspect(2)*obj.SCALEFACTOR];
        GF.OuterPosition=OPN
    end
    function AspectRatio0(obj,Aspect)  
        GF=gcf
        movegui(GF,[100,100])
        OP=GF.OuterPosition;
        DX=OP(3)-OP(1);
        DY=OP(4)-OP(2);
        OPN=[OP(1) OP(2) OP(1)+DX*Aspect(1) OP(2)+DX*Aspect(2)];
        GF.OuterPosition=OPN
    end
        function AspectRatio00(obj,Aspect)  
        GF=gcf
        movegui(GF,[100,100])
        OP=GF.OuterPosition;
        DX=OP(3)-OP(1);
        DY=OP(4)-OP(2);
        OPN=[OP(1) OP(2) OP(1)+1*Aspect(1) OP(2)+(1/DX)*Aspect(2)];
        GF.OuterPosition=OPN
        end
        function LegendTransparant(obj,FAC)  
            if nargin>1
            if FAC<0||FAC>1
                FAC=0.2;
            end
            else
                FAC=0.2
            end
        V = findobj(gcf, 'Type', 'Legend');
        V.BoxFace.ColorData(4)=100;  % 4x1 uint8
        set(V.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;FAC]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent
        end
        function NumColunms(obj,NCollunm)
                    V = findobj(gcf, 'Type', 'Legend');
                    set(V,'NumColumns',4)
        end

    function FontSize(obj,FontSize,LegendSize,TickSize,YRight)  
        hLegend = findobj(gcf, 'Type', 'Legend');
        XLabel = findobj(gcf, 'Type', 'xLabel');
        YLabel = findobj(gcf, 'Type', 'yLabel');
        ax = gca;
        ax.FontSize = TickSize*obj.SCALEFACTOR; 
    ax.XLabel.FontSize=FontSize*obj.SCALEFACTOR;
    ax.Title.FontSize=FontSize*obj.SCALEFACTOR
        ax.XLabel.FontSize=FontSize*obj.SCALEFACTOR;
ax.XLabel.Interpreter='latex'
ax.YLabel.Interpreter='latex'
            ax = gca;
    ax.YLabel.FontSize=FontSize*obj.SCALEFACTOR;

    try

            if YRight

        yyaxis right
            ax = gca;
    ax.YLabel.FontSize=FontSize*obj.SCALEFACTOR;
            end
    yyaxis left
            ax = gca;
    ax.YLabel.FontSize=FontSize*obj.SCALEFACTOR;
    
    catch
    
        
        
    end
%         allaxes = findall(gcf, 'type', 'axes');
%         allaxes.XLabel.FontSize=FontSize; allaxes.XLabel.Interpreter='latex'
%         allaxes.YLabel.FontSize=FontSize; allaxes.YLabel.Interpreter='latex'
         try
        hLegend.FontSize=LegendSize*obj.SCALEFACTOR;hLegend.Interpreter='latex'
         catch
         end

%         set(lgnd,'color','none');fyz
%         hLegend.Color='none'
    end
        
        
    
            function LineSize(obj,FontSize) 
        end
        function MAXBORDER(obj)
            ax=gca;
            ti=0.01
            ax.OuterPosition= ax.OuterPosition+[ ti ti -ti -ti ];
        end
    function MINBORDER(obj)
        ax = gca;
        outerpos = ax.OuterPosition;
        obj.OldSize=ax.Position;
        ti = ax.TightInset 
        left = outerpos(1) + ti(1);
        bottom = outerpos(2) + ti(2);
        ax_width = outerpos(3) - ti(1) - ti(3);
        ax_height = outerpos(4) - ti(2) - ti(4);
        ax_height=ax_height*0.99;
        ax_width=ax_width*0.99;
        ax.Position = [left bottom ax_width ax_height];

%STORE OLD VERSION
if size(obj.oldGca,1)==0
      obj.oldGca={(ax)}
      %ASPECTRATIO USING FIGURE AND GFC!  
      %GF.OuterPosition(3)=GF.OuterPosition(3)
      else
          obj.oldGca={obj.oldGca{:},(ax)}
      end

       end
       function ReMINBORDER(obj)
             ax = gca;
           ax.Position = obj.OldSize;
    
       end
              function STOREPOS(obj)
                    ax = gca;
                     GCAOLD=(get(ax,properties(ax)))
        if size(obj.oldGca,1)==0
            obj.oldGca={GCAOLD;properties(ax)}
        else
          obj.oldGca={obj.oldGca{:},{GCAOLD;properties(ax)}}
         end

              
              end
                     function EinarAspect2(obj,ASPECT)
                                ax=gca
                                TI=ax.TightInset
                                axPosOld=ax.Position
        
                                axPosition=([0 0 ASPECT(1) ASPECT(2)])
                               ax.OuterPosition =axPosition+[-TI(1) -TI(2) TI(1)+TI(3) TI(2)+TI(4)]
                                ax.Position=axPosition
                     end
                     
   
                                   
%        function MINBORDER(obj)
%            ax=gca
%            outerpos=ax.Position
%            TigthIn=ax.TightInset;
%            outerpos(4)=outerpos(4)*1.01;
%           outerpos(2)=outerpos(2)*1.01;
%            %ax.Position=[outerpos];
%            ax.OuterPosition =[outerpos+TigthIn];
%         % WE NEED TO THINK ABOUT WINDOWING. 
        
function SaveEPSyFig(obj,Name)
    %SHOULD LOAD THE PRE-MINBORDER VERSION FOR SAVE AS FIG..
     FileName=[obj.FolderDestination '/' Name]

    fprintf('Current destination: ')
    fprintf(FileName)
%    disp(FolderDestination)
    fprintf('\n Change in file to fix')
    k=waitforbuttonpress
    saveas(gcf,[FileName '.fig'])
    saveas(gcf,[FileName '.eps'],'epsc')
end
   function Return2OldDim(obj,i)
       Names=obj.oldGca{2,i}
       NK=size(Names,1)
       Data=obj.oldGca{1,i}
       for i=1:NK

           A=Names{i}
          B=Data{i}
        if strcmp('PlotBoxAspectRatio',A)
     %   a=Asl

            set(gca,A,B)
        end
            if strcmp('auto',B)
            continue
            end
         try
           
            set(gca,A,B)
         catch
        
         end
       end
   end
%        
%                  set(gca,'PlotBoxAspectRatio',obj.oldGca{i}.PlotBoxAspectRatio)
%        set(gca,'OuterPosition',obj.oldGca{i}.OuterPosition)
% 
%        set(gca,'Position',obj.oldGca{i}.Position)

       %Returns to old dimensions. For consistency purposes. 
   function COLORZ=GetDefaultColors(obj)
    
COLORZ=[         0    0.4470    0.7410;
    0.8500    0.3250    0.0980;
    0.9290    0.6940    0.1250;
    0.4940    0.1840    0.5560,
    0.4660    0.6740    0.1880;
    0.3010    0.7450    0.9330;
    0.6350    0.0780    0.1840];
   end
   end
end

