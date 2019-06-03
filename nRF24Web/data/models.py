from django.db import models
import uuid
# Create your models here.
class dataField(models.Model):
    fieldId = models.TextField(primary_key=True, default= hex(int(uuid.uuid4().hex[:8],16)), editable=False,unique = True)

class dataContent(models.Model):
    field = models.ForeignKey(dataField, on_delete=models.CASCADE)
    timestamp = models.DateTimeField(auto_now_add=True)
    data = models.TextField()

